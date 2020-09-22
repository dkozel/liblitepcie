/*
 * LitePCIe util
 *
 * Copyright (C) 2018-2020 / EnjoyDigital  / florent@enjoy-digital.fr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/poll.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>

#include "litepcie.h"
#include "config.h"
#include "csr.h"
#include "flags.h"

#include "liblitepcie.h"

static char litepcie_device[1024];
static int litepcie_device_num;
static bool force_flash = false;

sig_atomic_t keep_running = 1;

void intHandler(int dummy) {
    keep_running = 0;
}

/* info */

static void info(void)
{
    int fd;
    int i;
    unsigned char fpga_identification[256];

    fd = open(litepcie_device, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Could not init driver\n");
        exit(1);
    }

    for(i=0; i<256; i++)
        fpga_identification[i] = litepcie_readl(fd, CSR_IDENTIFIER_MEM_BASE + 4*i);
    printf("FPGA identification: %s\n", fpga_identification);
    printf("FPGA dna: 0x%08x%08x\n",
        litepcie_readl(fd, CSR_DNA_ID_ADDR + 4*0),
        litepcie_readl(fd, CSR_DNA_ID_ADDR + 4*1)
    );
    printf("FPGA temperature: %0.1f °C\n",
           (double)litepcie_readl(fd, CSR_XADC_TEMPERATURE_ADDR) * 503.975/4096 - 273.15);
    printf("FPGA vccint: %0.2f V\n",
           (double)litepcie_readl(fd, CSR_XADC_VCCINT_ADDR) / 4096 * 3);
    printf("FPGA vccaux: %0.2f V\n",
           (double)litepcie_readl(fd, CSR_XADC_VCCAUX_ADDR) / 4096 * 3);
    printf("FPGA vccbram: %0.2f V\n",
           (double)litepcie_readl(fd, CSR_XADC_VCCBRAM_ADDR) / 4096 * 3);
    close(fd);
}

#if 0
/* flash */

static void flash_progress(void *opaque, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    fflush(stdout);
    va_end(ap);
}

static void flash_program(uint32_t base, const uint8_t *buf1, int size1)
{
    int fd;

    uint32_t size;
    uint8_t *buf;
    int sector_size;
    int errors;

    fd = open(litepcie_device, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Could not init driver\n");
        exit(1);
    }

    sector_size = litepcie_flash_get_erase_block_size(fd);

    /* pad to sector_size */
    size = ((size1 + sector_size - 1) / sector_size) * sector_size;

    buf = malloc(size);
    memset(buf, 0, size);
    memcpy(buf, buf1, size1);

    printf("Programming (%d bytes at 0x%08x)\n", size, base);

    errors = litepcie_flash_write(fd, buf, base, size, flash_progress, NULL);

    /* result */
    if (errors) {
        printf("Failed %d errors\n", errors);
        exit(1);
    } else {
        printf("Success\n");
    }

    free(buf);

    close(fd);
}

static void flash_update(const char *filename, uint32_t offset)
{
    uint8_t *data;
    int size;
    FILE * f;
    int i;

    int fd = open(litepcie_device, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Could not init driver\n");
        exit(1);
    }

    char fpga_identification[256];
    for(i=0; i<256; i++) {
        char c = litepcie_readl(fd, CSR_IDENTIFIER_MEM_BASE + 4*i);
        if (c == ' ') {
            fpga_identification[i] = 0;
            break;
        }
        fpga_identification[i] = tolower(c);
    }
    close(fd);

    bool found_ident = !!strstr(filename, fpga_identification);
    if (!found_ident) {
        if (force_flash) {
            printf("Warning: ident (%s) not found in filename (%s), continuing\n",
                    fpga_identification, filename);
        } else {
            printf("Error: ident (%s) not found in filename (%s), aborting\n",
                    fpga_identification, filename);
            exit(1);
        }
    }

    f = fopen(filename, "rb");
    if (!f) {
        perror(filename);
        exit(1);
    }

    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    data = malloc(size);
    ssize_t ret = fread(data, size, 1, f);
    fclose(f);

    if (ret != 1) {
        perror(filename);
        return;
    }

    flash_program(offset, data, size);

    free(data);
}

static void flash_dump(const char *filename, uint32_t size, uint32_t offset)
{
    int fd;
    FILE * f;
    uint32_t base;
    uint32_t sector_size;
    uint8_t byte;
    int i;

    f = fopen(filename, "wb");
    if (!f) {
        perror(filename);
        exit(1);
    }

    fd = open(litepcie_device, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Could not init driver\n");
        exit(1);
    }

    base = offset;
    sector_size = litepcie_flash_get_erase_block_size(fd);
    for(i = 0; i < size; i++) {
        if ((i % sector_size) == 0) {
            printf("Dumping %08x\r", base + i);
            fflush(stdout);
        }
        byte = litepcie_flash_read(fd, base + i);
        fwrite(&byte, 1, 1, f);
    }

    fclose(f);

    close(fd);
}

static void flash_reload(void)
{
    int fd;

    fd = open(litepcie_device, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Could not init driver\n");
        exit(1);
    }

    /* reload fpga */
    litepcie_reload(fd);

    printf("================================================================\n");
    printf("= PLEASE REBOOT YOUR HARDWARE TO START WITH NEW FPGA GATEWARE =\n");
    printf("================================================================\n");

    close(fd);
}
#endif

/* dma */

static inline uint32_t add_mod_int(uint32_t a, uint32_t b, uint32_t m)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}

static inline uint32_t seed_to_data(uint32_t seed)
{
#if 1
    return seed * 69069 + 1;
#else
    return seed;
#endif
}

static void write_pn_data(uint32_t *buf, int count, uint32_t *pseed)
{
    int i;
    uint32_t seed;

    seed = *pseed;
    for(i = 0; i < count; i++) {
        buf[i] = seed_to_data(seed);
        seed = add_mod_int(seed, 1, DMA_BUFFER_SIZE/4);
    }
    *pseed = seed;
}

static int check_pn_data(uint32_t *buf, int count, uint32_t *pseed)
{
    int i, errors;
    uint32_t seed;

    errors = 0;
    seed = *pseed;
    for(i = 0; i < count; i++) {
        if (buf[i] != seed_to_data(seed)) {
            errors++;
        }
        seed = add_mod_int(seed, 1, DMA_BUFFER_SIZE/4);
    }
    *pseed = seed;
    return errors;
}

static void dma_test(void)
{
    struct pollfd fds;
    int ret;
    int i;
    ssize_t len;

    int64_t reader_hw_count, reader_sw_count, reader_sw_count_last;
    int64_t writer_hw_count, writer_sw_count;

    int64_t duration;
    int64_t last_time;

    uint32_t seed_wr;
    uint32_t seed_rd;

    uint32_t errors;

    char *buf_rd, *buf_wr;

    signal(SIGINT, intHandler);

    buf_rd = malloc(DMA_BUFFER_TOTAL_SIZE);
    buf_wr = malloc(DMA_BUFFER_TOTAL_SIZE);

    errors = 0;
    seed_wr = 0;
    seed_rd = 0;

    memset(buf_rd, 0, DMA_BUFFER_TOTAL_SIZE);
    memset(buf_wr, 0, DMA_BUFFER_TOTAL_SIZE);

    write_pn_data((uint32_t *) buf_wr, DMA_BUFFER_TOTAL_SIZE/4, &seed_wr);

    fds.fd = open(litepcie_device, O_RDWR | O_CLOEXEC);
    fds.events = POLLIN | POLLOUT;
    if (fds.fd < 0) {
        fprintf(stderr, "Could not init driver\n");
        exit(1);
    }

    /* request dma */
    if ((litepcie_request_dma_reader(fds.fd) == 0) |
        (litepcie_request_dma_writer(fds.fd) == 0)) {
        printf("DMA not available, exiting.\n");
        errors += 1;
        goto exit;
    }

    /* enable dma loopback*/
    litepcie_dma(fds.fd, 1);

    /* test loop */
    i = 0;
    reader_hw_count = 0;
    reader_sw_count = 0;
    reader_sw_count_last = 0;
    writer_hw_count = 0;
    writer_sw_count = 0;
    last_time = get_time_ms();
    for (;;) {
        /* exit loop on ctrl+c pressed */
        if (!keep_running)
            break;

        /* set / get dma */
        litepcie_dma_writer(fds.fd, 1, &writer_hw_count, &writer_sw_count);
        litepcie_dma_reader(fds.fd, 1, &reader_hw_count, &reader_sw_count);

        /* polling */
        ret = poll(&fds, 1, 100);
        if (ret <=  0) {
            continue;
        }

        /* read event */
        if (fds.revents & POLLIN) {
            len = read(fds.fd, buf_rd, DMA_BUFFER_TOTAL_SIZE);
            if(len >= 0) {
                uint32_t check_errors;
                check_errors = check_pn_data((uint32_t *) buf_rd, len/4, &seed_rd);
                if (writer_hw_count > DMA_BUFFER_COUNT)
                    errors += check_errors;
            }
        }

        /* write event */
        if (fds.revents & POLLOUT) {
            len = write(fds.fd, buf_wr, DMA_BUFFER_TOTAL_SIZE);
        }

        /* statistics */
        duration = get_time_ms() - last_time;
        if (duration > 200) {
            if(i%10 == 0)
                printf("\e[1mDMA_SPEED(Gbps) TX_BUFFERS RX_BUFFERS  DIFF  ERRORS\e[0m\n");
            i++;
            printf("%14.2f %10" PRIu64 " %10" PRIu64 " %6" PRIu64 " %7u\n",
                    (double)(reader_sw_count - reader_sw_count_last) * DMA_BUFFER_SIZE * 8 / ((double)duration * 1e6),
                    reader_sw_count,
                    writer_sw_count,
                    reader_sw_count - writer_sw_count,
                    errors);
            last_time = get_time_ms();
            reader_sw_count_last = reader_sw_count;
        }
    }

    litepcie_dma_reader(fds.fd, 0, &reader_hw_count, &reader_sw_count);
    litepcie_dma_writer(fds.fd, 0, &writer_hw_count, &writer_sw_count);

    litepcie_release_dma_reader(fds.fd);
    litepcie_release_dma_writer(fds.fd);

exit:
    free(buf_rd);
    free(buf_wr);

    close(fds.fd);
}


void scratch_test(void)
{
    int fd;

    fd = open(litepcie_device, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Could not init driver\n");
        exit(1);
    }

    printf("Write 0x12345678 to scratch register:\n");
    litepcie_writel(fd, CSR_CTRL_SCRATCH_ADDR, 0x12345678);
    printf("Read: 0x%08x\n", litepcie_readl(fd, CSR_CTRL_SCRATCH_ADDR));

    printf("Write 0xdeadbeef to scratch register:\n");
    litepcie_writel(fd, CSR_CTRL_SCRATCH_ADDR, 0xdeadbeef);
    printf("Read: 0x%08x\n", litepcie_readl(fd, CSR_CTRL_SCRATCH_ADDR));

    close(fd);
}

void uart_test(void)
{
    int fd;

    fd = open(litepcie_device, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Could not init driver\n");
        exit(1);
    }

    litepcie_writel(fd, CSR_CTRL_RESET_ADDR, 1); /* reset CPU */

    while (1) {
        if ((litepcie_readl(fd, CSR_UART_XOVER_RXEMPTY_ADDR) & 0x1) == 0) {
            printf("%c", litepcie_readl(fd, CSR_UART_XOVER_RXTX_ADDR) & 0xff);
        }
    }

    close(fd);
}

static void help(void)
{
    printf("LitePCIe utilities\n"
           "usage: litepcie_util [options] cmd [args...]\n"
           "\n"
           "options:\n"
           "-h                                Help\n"
           "-f                                Force flashing when ident not found\n"
           "-c device_num                     Select the device (default = 0)\n"
           "\n"
           "available commands:\n"
           "info                              Board information\n"
           "dma_test                          Test DMA  (loopback in FPGA)\n"
           "scratch_test                      Test Scratch register\n"
           "uart_test                         Test CPU Crossover UART\n"
           "\n"
           "flash_update filename [offset]    Update FPGA gateware\n"
           "flash_dump filename size [offset] Dump FPGA gateware\n"
           "flash_reload                      Reload FPGA gateware\n"
           );
    exit(1);
}

int main(int argc, char **argv)
{
    const char *cmd;
    int c;

    litepcie_device_num = 0;

    /* parameters */
    for(;;) {
        c = getopt(argc, argv, "hfc:");
        if (c == -1)
            break;
        switch(c) {
        case 'h':
            help();
            break;
        case 'f':
            force_flash = true;
            break;
        case 'c':
            litepcie_device_num = atoi(optarg);
            break;
        default:
            exit(1);
        }
    }

    if (optind >= argc)
        help();

    /* select device */
    snprintf(litepcie_device, sizeof(litepcie_device), "/dev/litepcie%d", litepcie_device_num);

    cmd = argv[optind++];

    if (!strcmp(cmd, "info"))
        info();
    else if (!strcmp(cmd, "dma_test"))
        dma_test();
    else if (!strcmp(cmd, "scratch_test"))
        scratch_test();
    else if (!strcmp(cmd, "uart_test"))
        uart_test();
#if 0
    else if (!strcmp(cmd, "flash_update")) {
        const char *filename;
        uint32_t offset = 0;
        if (optind + 1 > argc)
            goto show_help;
        filename = argv[optind++];
        if (optind < argc)
            offset = strtoul(argv[optind++], NULL, 0);
        flash_update(filename, offset);
    }
    else if (!strcmp(cmd, "flash_dump")) {
        const char *filename;
        uint32_t size = 0;
        uint32_t offset = 0;
        if (optind + 2 > argc)
            goto show_help;
        filename = argv[optind++];
        size = strtoul(argv[optind++], NULL, 0);
        if (optind < argc)
            offset = strtoul(argv[optind++], NULL, 0);
        flash_dump(filename, size, offset);
    }
    else if (!strcmp(cmd, "flash_reload"))
        flash_reload();
#endif
    else
show_help:
        help();

    return 0;
}
