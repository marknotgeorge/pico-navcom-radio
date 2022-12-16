#include <stdio.h>
#include "pico/stdlib.h"

#include "bsp/board.h"

#include "tusb.h"

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




