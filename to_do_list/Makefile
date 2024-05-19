DIR_Config	 = ./lib/Config
DIR_EPD		 = ./lib/e-Paper
DIR_FONTS	 = ./lib/Fonts
DIR_GUI		 = ./lib/GUI
DIR_BIN		 = ./bin

OBJS = $(DIR_BIN)/DEV_Config.o $(DIR_BIN)/dev_hardware_SPI.o $(DIR_BIN)/EPD_4in2_V2.o $(DIR_BIN)/font24.o $(DIR_BIN)/GUI_BMPfile.o \
       $(DIR_BIN)/GUI_Paint.o $(DIR_BIN)/main.o $(DIR_BIN)/RPI_gpiod.o

epd: $(OBJS)
    gcc -o epd $(OBJS)

DEV_Config.o: DEV_Config.c DEV_Config.h RPI_gpiod.h
    gcc -c DEV_Config.c

dev_hardware_SPI.o: dev_hardware_SPI.c dev_hardware_SPI.h
    gcc -c dev_hardware_SPI.c

EPD_4in2_V2.o: EPD_4in2_V2.c EPD_4in2_V2.h Debug.h
    gcc -c EPD_4in2_V2.c

font24.o: font24.c fonts.h
    gcc -c font24.c

GUI_BMPfile.o: GUI_BMPfile.c GUI_BMPfile.h GUI_Paint.h Debug.h
    gcc -c GUI_BMPfile.c

GUI_Paint.o: GUI_Paint.c
    gcc -c GUI_Paint.c

main.o: main.c EPD_4in2_V2.h DEV_Config.h GUI_Paint.h readFile.h
    gcc -c main.c

RPI_gpiod.o: RPI_gpiod.c RPI_gpiod.h
    gcc -c RPI_gpiod.c

clean :
	rm $(DIR_BIN)/*.* 
	rm $(TARGET) 

