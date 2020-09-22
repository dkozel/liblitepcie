cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_EXTENSIONS ON)

project(libLitePCIe VERSION 1.0
    DESCRIPTION "Userspace library for LitePCIe"
    LANGUAGES C)

add_library(litepcie SHARED src/liblitepcie.c include/liblitepcie.h)
set(CMAKE_C_FLAGS "-O2 -Wall -g")
target_link_libraries(litepcie rt m)

target_include_directories(litepcie 
    PRIVATE kernel
    PUBLIC include)
set_target_properties(litepcie PROPERTIES C_STANDARD 99)

add_executable(litepcie_util apps/litepcie_util.c)
target_link_libraries(litepcie_util PUBLIC litepcie)
target_include_directories(litepcie_util
    PRIVATE kernel)

add_executable(litepcie_test apps/litepcie_test.c)
target_link_libraries(litepcie_test PUBLIC litepcie)
target_include_directories(litepcie_test
    PRIVATE kernel)

include(GNUInstallDirs)
install(
    TARGETS litepcie litepcie_util litepcie_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/LitePCIe)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK") #required
INCLUDE(CPack)
