//--------------------------------------------------------------------------------
// Auto-generated by Migen (--------) & LiteX (05815c4e) on 2020-04-28 16:55:08
//--------------------------------------------------------------------------------
#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H

/* ctrl */
#define CSR_CTRL_BASE 0x82000000L
#define CSR_CTRL_RESET_ADDR 0x82000000L
#define CSR_CTRL_RESET_SIZE 1
#define CSR_CTRL_SCRATCH_ADDR 0x82000004L
#define CSR_CTRL_SCRATCH_SIZE 1
#define CSR_CTRL_BUS_ERRORS_ADDR 0x82000008L
#define CSR_CTRL_BUS_ERRORS_SIZE 1

/* identifier_mem */
#define CSR_IDENTIFIER_MEM_BASE 0x82001000L

/* uart */
#define CSR_UART_BASE 0x82002000L
#define CSR_UART_RXTX_ADDR 0x82002000L
#define CSR_UART_RXTX_SIZE 1
#define CSR_UART_TXFULL_ADDR 0x82002004L
#define CSR_UART_TXFULL_SIZE 1
#define CSR_UART_RXEMPTY_ADDR 0x82002008L
#define CSR_UART_RXEMPTY_SIZE 1
#define CSR_UART_EV_STATUS_ADDR 0x8200200cL
#define CSR_UART_EV_STATUS_SIZE 1
#define CSR_UART_EV_PENDING_ADDR 0x82002010L
#define CSR_UART_EV_PENDING_SIZE 1
#define CSR_UART_EV_ENABLE_ADDR 0x82002014L
#define CSR_UART_EV_ENABLE_SIZE 1
#define CSR_UART_XOVER_RXTX_ADDR 0x82002018L
#define CSR_UART_XOVER_RXTX_SIZE 1
#define CSR_UART_XOVER_TXFULL_ADDR 0x8200201cL
#define CSR_UART_XOVER_TXFULL_SIZE 1
#define CSR_UART_XOVER_RXEMPTY_ADDR 0x82002020L
#define CSR_UART_XOVER_RXEMPTY_SIZE 1
#define CSR_UART_XOVER_EV_STATUS_ADDR 0x82002024L
#define CSR_UART_XOVER_EV_STATUS_SIZE 1
#define CSR_UART_XOVER_EV_PENDING_ADDR 0x82002028L
#define CSR_UART_XOVER_EV_PENDING_SIZE 1
#define CSR_UART_XOVER_EV_ENABLE_ADDR 0x8200202cL
#define CSR_UART_XOVER_EV_ENABLE_SIZE 1

/* timer0 */
#define CSR_TIMER0_BASE 0x82002800L
#define CSR_TIMER0_LOAD_ADDR 0x82002800L
#define CSR_TIMER0_LOAD_SIZE 1
#define CSR_TIMER0_RELOAD_ADDR 0x82002804L
#define CSR_TIMER0_RELOAD_SIZE 1
#define CSR_TIMER0_EN_ADDR 0x82002808L
#define CSR_TIMER0_EN_SIZE 1
#define CSR_TIMER0_UPDATE_VALUE_ADDR 0x8200280cL
#define CSR_TIMER0_UPDATE_VALUE_SIZE 1
#define CSR_TIMER0_VALUE_ADDR 0x82002810L
#define CSR_TIMER0_VALUE_SIZE 1
#define CSR_TIMER0_EV_STATUS_ADDR 0x82002814L
#define CSR_TIMER0_EV_STATUS_SIZE 1
#define CSR_TIMER0_EV_PENDING_ADDR 0x82002818L
#define CSR_TIMER0_EV_PENDING_SIZE 1
#define CSR_TIMER0_EV_ENABLE_ADDR 0x8200281cL
#define CSR_TIMER0_EV_ENABLE_SIZE 1

/* crg */
#define CSR_CRG_BASE 0x82003000L
#define CSR_CRG_RST_ADDR 0x82003000L
#define CSR_CRG_RST_SIZE 1

/* dna */
#define CSR_DNA_BASE 0x82003800L
#define CSR_DNA_ID_ADDR 0x82003800L
#define CSR_DNA_ID_SIZE 2

/* xadc */
#define CSR_XADC_BASE 0x82004000L
#define CSR_XADC_TEMPERATURE_ADDR 0x82004000L
#define CSR_XADC_TEMPERATURE_SIZE 1
#define CSR_XADC_VCCINT_ADDR 0x82004004L
#define CSR_XADC_VCCINT_SIZE 1
#define CSR_XADC_VCCAUX_ADDR 0x82004008L
#define CSR_XADC_VCCAUX_SIZE 1
#define CSR_XADC_VCCBRAM_ADDR 0x8200400cL
#define CSR_XADC_VCCBRAM_SIZE 1
#define CSR_XADC_EOC_ADDR 0x82004010L
#define CSR_XADC_EOC_SIZE 1
#define CSR_XADC_EOS_ADDR 0x82004014L
#define CSR_XADC_EOS_SIZE 1

/* icap */
#define CSR_ICAP_BASE 0x82004800L
#define CSR_ICAP_ADDR_ADDR 0x82004800L
#define CSR_ICAP_ADDR_SIZE 1
#define CSR_ICAP_DATA_ADDR 0x82004804L
#define CSR_ICAP_DATA_SIZE 1
#define CSR_ICAP_SEND_ADDR 0x82004808L
#define CSR_ICAP_SEND_SIZE 1
#define CSR_ICAP_DONE_ADDR 0x8200480cL
#define CSR_ICAP_DONE_SIZE 1

/* ddrphy */
#define CSR_DDRPHY_BASE 0x82005000L
#define CSR_DDRPHY_HALF_SYS8X_TAPS_ADDR 0x82005000L
#define CSR_DDRPHY_HALF_SYS8X_TAPS_SIZE 1
#define CSR_DDRPHY_WLEVEL_EN_ADDR 0x82005004L
#define CSR_DDRPHY_WLEVEL_EN_SIZE 1
#define CSR_DDRPHY_WLEVEL_STROBE_ADDR 0x82005008L
#define CSR_DDRPHY_WLEVEL_STROBE_SIZE 1
#define CSR_DDRPHY_CDLY_RST_ADDR 0x8200500cL
#define CSR_DDRPHY_CDLY_RST_SIZE 1
#define CSR_DDRPHY_CDLY_INC_ADDR 0x82005010L
#define CSR_DDRPHY_CDLY_INC_SIZE 1
#define CSR_DDRPHY_DLY_SEL_ADDR 0x82005014L
#define CSR_DDRPHY_DLY_SEL_SIZE 1
#define CSR_DDRPHY_RDLY_DQ_RST_ADDR 0x82005018L
#define CSR_DDRPHY_RDLY_DQ_RST_SIZE 1
#define CSR_DDRPHY_RDLY_DQ_INC_ADDR 0x8200501cL
#define CSR_DDRPHY_RDLY_DQ_INC_SIZE 1
#define CSR_DDRPHY_RDLY_DQ_BITSLIP_RST_ADDR 0x82005020L
#define CSR_DDRPHY_RDLY_DQ_BITSLIP_RST_SIZE 1
#define CSR_DDRPHY_RDLY_DQ_BITSLIP_ADDR 0x82005024L
#define CSR_DDRPHY_RDLY_DQ_BITSLIP_SIZE 1

/* sdram */
#define CSR_SDRAM_BASE 0x82005800L
#define CSR_SDRAM_DFII_CONTROL_ADDR 0x82005800L
#define CSR_SDRAM_DFII_CONTROL_SIZE 1
#define CSR_SDRAM_DFII_PI0_COMMAND_ADDR 0x82005804L
#define CSR_SDRAM_DFII_PI0_COMMAND_SIZE 1
#define CSR_SDRAM_DFII_PI0_COMMAND_ISSUE_ADDR 0x82005808L
#define CSR_SDRAM_DFII_PI0_COMMAND_ISSUE_SIZE 1
#define CSR_SDRAM_DFII_PI0_ADDRESS_ADDR 0x8200580cL
#define CSR_SDRAM_DFII_PI0_ADDRESS_SIZE 1
#define CSR_SDRAM_DFII_PI0_BADDRESS_ADDR 0x82005810L
#define CSR_SDRAM_DFII_PI0_BADDRESS_SIZE 1
#define CSR_SDRAM_DFII_PI0_WRDATA_ADDR 0x82005814L
#define CSR_SDRAM_DFII_PI0_WRDATA_SIZE 1
#define CSR_SDRAM_DFII_PI0_RDDATA_ADDR 0x82005818L
#define CSR_SDRAM_DFII_PI0_RDDATA_SIZE 1
#define CSR_SDRAM_DFII_PI1_COMMAND_ADDR 0x8200581cL
#define CSR_SDRAM_DFII_PI1_COMMAND_SIZE 1
#define CSR_SDRAM_DFII_PI1_COMMAND_ISSUE_ADDR 0x82005820L
#define CSR_SDRAM_DFII_PI1_COMMAND_ISSUE_SIZE 1
#define CSR_SDRAM_DFII_PI1_ADDRESS_ADDR 0x82005824L
#define CSR_SDRAM_DFII_PI1_ADDRESS_SIZE 1
#define CSR_SDRAM_DFII_PI1_BADDRESS_ADDR 0x82005828L
#define CSR_SDRAM_DFII_PI1_BADDRESS_SIZE 1
#define CSR_SDRAM_DFII_PI1_WRDATA_ADDR 0x8200582cL
#define CSR_SDRAM_DFII_PI1_WRDATA_SIZE 1
#define CSR_SDRAM_DFII_PI1_RDDATA_ADDR 0x82005830L
#define CSR_SDRAM_DFII_PI1_RDDATA_SIZE 1
#define CSR_SDRAM_DFII_PI2_COMMAND_ADDR 0x82005834L
#define CSR_SDRAM_DFII_PI2_COMMAND_SIZE 1
#define CSR_SDRAM_DFII_PI2_COMMAND_ISSUE_ADDR 0x82005838L
#define CSR_SDRAM_DFII_PI2_COMMAND_ISSUE_SIZE 1
#define CSR_SDRAM_DFII_PI2_ADDRESS_ADDR 0x8200583cL
#define CSR_SDRAM_DFII_PI2_ADDRESS_SIZE 1
#define CSR_SDRAM_DFII_PI2_BADDRESS_ADDR 0x82005840L
#define CSR_SDRAM_DFII_PI2_BADDRESS_SIZE 1
#define CSR_SDRAM_DFII_PI2_WRDATA_ADDR 0x82005844L
#define CSR_SDRAM_DFII_PI2_WRDATA_SIZE 1
#define CSR_SDRAM_DFII_PI2_RDDATA_ADDR 0x82005848L
#define CSR_SDRAM_DFII_PI2_RDDATA_SIZE 1
#define CSR_SDRAM_DFII_PI3_COMMAND_ADDR 0x8200584cL
#define CSR_SDRAM_DFII_PI3_COMMAND_SIZE 1
#define CSR_SDRAM_DFII_PI3_COMMAND_ISSUE_ADDR 0x82005850L
#define CSR_SDRAM_DFII_PI3_COMMAND_ISSUE_SIZE 1
#define CSR_SDRAM_DFII_PI3_ADDRESS_ADDR 0x82005854L
#define CSR_SDRAM_DFII_PI3_ADDRESS_SIZE 1
#define CSR_SDRAM_DFII_PI3_BADDRESS_ADDR 0x82005858L
#define CSR_SDRAM_DFII_PI3_BADDRESS_SIZE 1
#define CSR_SDRAM_DFII_PI3_WRDATA_ADDR 0x8200585cL
#define CSR_SDRAM_DFII_PI3_WRDATA_SIZE 1
#define CSR_SDRAM_DFII_PI3_RDDATA_ADDR 0x82005860L
#define CSR_SDRAM_DFII_PI3_RDDATA_SIZE 1

/* pcie_phy */
#define CSR_PCIE_PHY_BASE 0x82006000L
#define CSR_PCIE_PHY_LINK_UP_ADDR 0x82006000L
#define CSR_PCIE_PHY_LINK_UP_SIZE 1
#define CSR_PCIE_PHY_MSI_ENABLE_ADDR 0x82006004L
#define CSR_PCIE_PHY_MSI_ENABLE_SIZE 1
#define CSR_PCIE_PHY_BUS_MASTER_ENABLE_ADDR 0x82006008L
#define CSR_PCIE_PHY_BUS_MASTER_ENABLE_SIZE 1
#define CSR_PCIE_PHY_MAX_REQUEST_SIZE_ADDR 0x8200600cL
#define CSR_PCIE_PHY_MAX_REQUEST_SIZE_SIZE 1
#define CSR_PCIE_PHY_MAX_PAYLOAD_SIZE_ADDR 0x82006010L
#define CSR_PCIE_PHY_MAX_PAYLOAD_SIZE_SIZE 1

/* pcie_dma0 */
#define CSR_PCIE_DMA0_BASE 0x82006800L
#define CSR_PCIE_DMA0_WRITER_ENABLE_ADDR 0x82006800L
#define CSR_PCIE_DMA0_WRITER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDR 0x82006804L
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDRESS_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDRESS_SIZE 32
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDR 0x8200680cL
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_PROG_N_ADDR 0x82006810L
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_ADDR 0x82006814L
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LEVEL_ADDR 0x82006818L
#define CSR_PCIE_DMA0_WRITER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_FLUSH_ADDR 0x8200681cL
#define CSR_PCIE_DMA0_WRITER_TABLE_FLUSH_SIZE 1
#define CSR_PCIE_DMA0_READER_ENABLE_ADDR 0x82006820L
#define CSR_PCIE_DMA0_READER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDR 0x82006824L
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDRESS_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDRESS_SIZE 32
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDR 0x8200682cL
#define CSR_PCIE_DMA0_READER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_PROG_N_ADDR 0x82006830L
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_ADDR 0x82006834L
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA0_READER_TABLE_LEVEL_ADDR 0x82006838L
#define CSR_PCIE_DMA0_READER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_FLUSH_ADDR 0x8200683cL
#define CSR_PCIE_DMA0_READER_TABLE_FLUSH_SIZE 1
#define CSR_PCIE_DMA0_LOOPBACK_ENABLE_ADDR 0x82006840L
#define CSR_PCIE_DMA0_LOOPBACK_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_DEPTH_ADDR 0x82006844L
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_DEPTH_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_LEVEL_ADDR 0x82006848L
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_DEPTH_ADDR 0x8200684cL
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_DEPTH_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_LEVEL_ADDR 0x82006850L
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_LEVEL_SIZE 1

/* pcie_dma1 */
#define CSR_PCIE_DMA1_BASE 0x82007000L
#define CSR_PCIE_DMA1_WRITER_ENABLE_ADDR 0x82007000L
#define CSR_PCIE_DMA1_WRITER_ENABLE_SIZE 1
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_ADDR 0x82007004L
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_ADDRESS_OFFSET 0
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_ADDRESS_SIZE 32
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA1_WRITER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA1_WRITER_TABLE_WE_ADDR 0x8200700cL
#define CSR_PCIE_DMA1_WRITER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA1_WRITER_TABLE_LOOP_PROG_N_ADDR 0x82007010L
#define CSR_PCIE_DMA1_WRITER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA1_WRITER_TABLE_LOOP_STATUS_ADDR 0x82007014L
#define CSR_PCIE_DMA1_WRITER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA1_WRITER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA1_WRITER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA1_WRITER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA1_WRITER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA1_WRITER_TABLE_LEVEL_ADDR 0x82007018L
#define CSR_PCIE_DMA1_WRITER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA1_WRITER_TABLE_FLUSH_ADDR 0x8200701cL
#define CSR_PCIE_DMA1_WRITER_TABLE_FLUSH_SIZE 1
#define CSR_PCIE_DMA1_READER_ENABLE_ADDR 0x82007020L
#define CSR_PCIE_DMA1_READER_ENABLE_SIZE 1
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_ADDR 0x82007024L
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_ADDRESS_OFFSET 0
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_ADDRESS_SIZE 32
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA1_READER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA1_READER_TABLE_WE_ADDR 0x8200702cL
#define CSR_PCIE_DMA1_READER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA1_READER_TABLE_LOOP_PROG_N_ADDR 0x82007030L
#define CSR_PCIE_DMA1_READER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA1_READER_TABLE_LOOP_STATUS_ADDR 0x82007034L
#define CSR_PCIE_DMA1_READER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA1_READER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA1_READER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA1_READER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA1_READER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA1_READER_TABLE_LEVEL_ADDR 0x82007038L
#define CSR_PCIE_DMA1_READER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA1_READER_TABLE_FLUSH_ADDR 0x8200703cL
#define CSR_PCIE_DMA1_READER_TABLE_FLUSH_SIZE 1
#define CSR_PCIE_DMA1_LOOPBACK_ENABLE_ADDR 0x82007040L
#define CSR_PCIE_DMA1_LOOPBACK_ENABLE_SIZE 1
#define CSR_PCIE_DMA1_BUFFERING_READER_FIFO_DEPTH_ADDR 0x82007044L
#define CSR_PCIE_DMA1_BUFFERING_READER_FIFO_DEPTH_SIZE 1
#define CSR_PCIE_DMA1_BUFFERING_READER_FIFO_LEVEL_ADDR 0x82007048L
#define CSR_PCIE_DMA1_BUFFERING_READER_FIFO_LEVEL_SIZE 1
#define CSR_PCIE_DMA1_BUFFERING_WRITER_FIFO_DEPTH_ADDR 0x8200704cL
#define CSR_PCIE_DMA1_BUFFERING_WRITER_FIFO_DEPTH_SIZE 1
#define CSR_PCIE_DMA1_BUFFERING_WRITER_FIFO_LEVEL_ADDR 0x82007050L
#define CSR_PCIE_DMA1_BUFFERING_WRITER_FIFO_LEVEL_SIZE 1

/* pcie_msi */
#define CSR_PCIE_MSI_BASE 0x82007800L
#define CSR_PCIE_MSI_ENABLE_ADDR 0x82007800L
#define CSR_PCIE_MSI_ENABLE_SIZE 1
#define CSR_PCIE_MSI_CLEAR_ADDR 0x82007804L
#define CSR_PCIE_MSI_CLEAR_SIZE 1
#define CSR_PCIE_MSI_VECTOR_ADDR 0x82007808L
#define CSR_PCIE_MSI_VECTOR_SIZE 1

#endif
