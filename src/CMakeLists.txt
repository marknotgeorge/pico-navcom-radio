add_executable(pico-navcom-radio
    main.cpp
)

pico_enable_stdio_usb(pico-navcom-radio 1)
pico_enable_stdio_uart(pico-navcom-radio 1)

pico_add_extra_outputs(pico-navcom-radio)

target_link_libraries(pico-navcom-radio pico_stdlib)

