#include "EPD_4in2_V2.h"    // E-paper library header
#include "DEV_Config.h"     // Device configuration library header (for GPIO/SPI initialization)
#include <stdlib.h>         // For dynamic memory allocation
#include <stdio.h>          // For printf function
#include "GUI_Paint.h"
#include <string.h>  // Include the string.h header for strlen()


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
    
    // test array
    // Define an array of pointers to char
    const char *test[] = {"missing to do", "chapter15 projects"};
    int n = sizeof(test) / sizeof(test[0]);
    int place = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d", place);
        Paint_DrawString_EN(10, 20 + place, test[i], &Font24, WHITE, BLACK);
        printf("%s\n", test[i]);
        place += 60;
    }
    // Paint_DrawString_EN(10, 20, test, &Font20, WHITE, BLACK);
    // Draw a string in English
    // Paint_DrawString_EN(10, 20, "hello world ", &FontCustom20, WHITE, BLACK);
    // Paint_DrawString_EN(10, 50, "hello world", &FontCustom8_20, WHITE, BLACK);
    // Paint_DrawString_EN(10, 80, "hello world", &FontCustom9_20, WHITE, BLACK);
    // Paint_DrawString_EN(10, 110, "hello world", &Font20, WHITE, BLACK);
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
