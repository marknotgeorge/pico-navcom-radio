cmake_minimum_required(VERSION 3.12)

# Pull in Pico SDK
include(pico_sdk_import.cmake)

project(pico-navcom-radio C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(pico-navcom-radio 
    src/main.cpp
    src/usb_descriptors.c
    Pico-I2C-LCD/LCD_I2C.cpp)

target_include_directories(pico-navcom-radio PUBLIC include Pico-I2C-LCD)

target_link_libraries(pico-navcom-radio pico_stdlib tinyusb_device tinyusb_board hardware_i2c)

pico_enable_stdio_uart(pico-navcom-radio 1)

pico_add_extra_outputs(pico-navcom-radio)

