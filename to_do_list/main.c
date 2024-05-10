#include "EPD_4in2_V2.h"    // E-paper library header
#include "DEV_Config.h"     // Device configuration library header (for GPIO/SPI initialization)
#include <stdlib.h>         // For dynamic memory allocation
#include <stdio.h>          // For printf function
#include "fonts.h"
#include "GUI_Paint.h"

int main() {
    printf("EPD_4IN2_V2_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }

    printf("e-Paper Init and Clear...\r\n");
    EPD_4IN2_V2_Init();
    EPD_4IN2_V2_Clear();
    
    // Initialize for 4-gray level display
    // EPD_4IN2_V2_Init_4Gray();
    printf("Drawing string..\n");
    Paint_DrawString_EN(10, 0, "waveshare", &Font16, BLACK, WHITE);

    // Wait for a few seconds to observe the image
    DEV_Delay_ms(2000);

    // Go to sleep mode to save power
    EPD_4IN2_V2_Sleep();

    // Deinitialize the module
    DEV_Module_Exit();

    return 0;
}
