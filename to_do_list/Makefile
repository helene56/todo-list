DIR_Config	 = ./lib/Config
DIR_EPD		 = ./lib/e-Paper
DIR_FONTS	 = ./lib/Fonts
DIR_GUI		 = ./lib/GUI
DIR_BIN		 = ./bin

OBJS = $(DIR_BIN)/DEV_Config.o $(DIR_BIN)/dev_hardware_SPI.o $(DIR_BIN)/EPD_4in2_V2.o $(DIR_BIN)/font24.o $(DIR_BIN)/GUI_BMPfile.o \
       $(DIR_BIN)/GUI_Paint.o $(DIR_BIN)/main.o $(DIR_BIN)/RPI_gpiod.o

epd: $(OBJS)
    gcc -o epd $(OBJS)

$(DIR_BIN)/DEV_Config.o: $(DIR_Config)/DEV_Config.c $(DIR_Config)DEV_Config.h $(DIR_Config)RPI_gpiod.h
    gcc -o $(DIR_BIN)/DEV_Config.o -c $(DIR_Config)DEV_Config.c

$(DIR_BIN)/dev_hardware_SPI.o: $(DIR_Config)/dev_hardware_SPI.c $(DIR_Config)/dev_hardware_SPI.h
    gcc -o $(DIR_BIN)/dev_hardware_SPI.o -c dev_hardware_SPI.c

$(DIR_BIN)/EPD_4in2_V2.o: $(DIR_EPD)/EPD_4in2_V2.c $(DIR_EPD)/EPD_4in2_V2.h $(DIR_Config)/Debug.h
    gcc -o $(DIR_BIN)/EPD_4in2_V2.o -c EPD_4in2_V2.c

$(DIR_BIN)/font24.o: $(DIR_FONTS)/font24.c $(DIR_FONTS)/fonts.h
    gcc -o $(DIR_BIN)/font24.o -c font24.c

$(DIR_BIN)/GUI_BMPfile.o: $(DIR_GUI)/GUI_BMPfile.c $(DIR_GUI)/GUI_BMPfile.h $(DIR_GUI)/GUI_Paint.h $(DIR_Config)/Debug.h
    gcc -o $(DIR_BIN)/GUI_BMPfile.o -c GUI_BMPfile.c

$(DIR_BIN)/GUI_Paint.o: $(DIR_GUI)/GUI_Paint.c
    gcc -o $(DIR_BIN)/GUI_Paint.o -c GUI_Paint.c

$(DIR_BIN)/main.o: main.c $(DIR_EPD)/EPD_4in2_V2.h $(DIR_Config)/DEV_Config.h $(DIR_GUI)/GUI_Paint.h readFile.h
    gcc -o $(DIR_BIN)/main.o -c main.c

$(DIR_BIN)/RPI_gpiod.o: $(DIR_Config)/RPI_gpiod.c $(DIR_Config)/RPI_gpiod.h
    gcc -o $(DIR_BIN)/RPI_gpiod.o -c RPI_gpiod.c

clean :
	rm $(DIR_BIN)/*.* 
	rm epd

