#include <stdio.h>
#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"
#include "LCD_I2C.hpp"
#include <memory>

#define ONBOARD_LED 25
#define I2C_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4


#define ONBOARD_LED 25

void cdc_task(void);
void parse_cdc_input(char buf[], uint32_t count);

int main()
{
    board_init();
    stdio_init_all();
    tusb_init();
    gpio_init(ONBOARD_LED);
    gpio_set_dir(ONBOARD_LED, GPIO_OUT);

    auto lcd = std::make_unique<LCD_I2C>(I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS, i2c_default, PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN);

    lcd->BacklightOn();
    lcd->SetCursor(0, 7);
    lcd->PrintString("NAVCOM");
    
    while (1)
    {
        tud_task();
        cdc_task();
    }
}

void cdc_task(void)
{
    if (tud_cdc_available())
    {
        char buf[64];
        uint32_t count = tud_cdc_read(buf, sizeof(buf));       

        parse_cdc_input(buf, count);
    }
}

void parse_cdc_input(char buf[], uint32_t count)
{
    printf("Received %d bytes.\r\n", count);
    printf("Received: %s", buf);
    
}




