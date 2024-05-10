#include "EPD_4in2_V2.h"    // E-paper library header
#include "DEV_Config.h"     // Device configuration library header (for GPIO/SPI initialization)
#include <stdlib.h>         // For dynamic memory allocation
#include <stdio.h>          // For printf function
#include "GUI_Paint.h"

int main() {
    printf("EPD_4IN2_V2_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }

    printf("e-Paper Init and Clear...\r\n");
    EPD_4IN2_V2_Init();  // Initialize the e-Paper display
    EPD_4IN2_V2_Clear();  // Clear the display
    DEV_Delay_ms(500);  // Delay to allow the display to refresh

    // Create a new image cache
    UBYTE *BlackImage;
    UWORD Imagesize = ((EPD_4IN2_V2_WIDTH % 8 == 0)? (EPD_4IN2_V2_WIDTH / 8): (EPD_4IN2_V2_WIDTH / 8 + 1)) * EPD_4IN2_V2_HEIGHT;
    if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;  // Check for successful memory allocation
    }
    Paint_NewImage(BlackImage, EPD_4IN2_V2_WIDTH, EPD_4IN2_V2_HEIGHT, 0, WHITE);  // Create a new image

    // Select the image for drawing
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);  // Clear the image with a white background
    printf("drawing string...\r\n");
    // Draw a string in English
    Paint_DrawString_EN(10, 20, "hello world", &Font12, BLACK, WHITE);  // Position at x=10, y=20, font size 12
    printf("drew string...\r\n");
    // Display the image on the e-Paper
    EPD_4IN2_V2_Display(BlackImage);
    // Wait for a few seconds to observe the image
    DEV_Delay_ms(2000);

    // Go to sleep mode to save power
    EPD_4IN2_V2_Sleep();

    // Deinitialize the module
    DEV_Module_Exit();

    return 0;
}