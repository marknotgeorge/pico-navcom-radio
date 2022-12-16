cmake_minimum_required(VERSION 3.12)

# Pull in Pico SDK
include(pico_sdk_import.cmake)

project(pico-navcom-radio C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(pico-navcom-radio)

target_sources(pico-navcom-radio PUBLIC
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/usb_descriptors.c
)

target_include_directories(pico-navcom-radio PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)

pico_enable_stdio_uart(pico-navcom-radio 1)


target_link_libraries(pico-navcom-radio pico_stdlib tinyusb_device tinyusb_board)

pico_add_extra_outputs(pico-navcom-radio)

