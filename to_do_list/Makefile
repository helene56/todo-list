# Project Directories
DIR_Config    = ./lib/Config
DIR_EPD       = ./lib/e-Paper
DIR_FONTS     = ./lib/Fonts
DIR_GUI       = ./lib/GUI
DIR_BIN       = ./bin

# Specify your main program file and any additional source files directly
OBJ_C_MAIN    = ./main.c # Main program source file
OBJ_C_EPD     = ${DIR_EPD}/EPD_4in2_V2.c # Specific e-Paper driver source file

# Combine all source files
OBJ_C         = $(OBJ_C_EPD) $(OBJ_C_MAIN) $(wildcard ${DIR_GUI}/*.c ${DIR_FONTS}/*.c ImageData.c)
OBJ_O         = $(patsubst %.c,${DIR_BIN}/%.o,$(notdir ${OBJ_C}))

# test
#OBJ_C = $(wildcard ${OBJ_C_EPD} ${DIR_GUI}/*.c ${DIR_FONTS}/*.c $(OBJ_C_MAIN))
#OBJ_C = $(wildcard ${OBJ_C_EPD} ${DIR_GUI}/*.c ${OBJ_C_MAIN} ImageData.c ${DIR_FONTS}/*.c )
# libriaries
RPI_DEV_C = $(wildcard $(DIR_BIN)/dev_hardware_SPI.o $(DIR_BIN)/RPI_gpiod.o $(DIR_BIN)/DEV_Config.o )

DEBUG = -D DEBUG

USELIB_RPI = USE_LGPIO_LIB


LIB_RPI=-Wl,--gc-sections
ifeq ($(USELIB_RPI), USE_BCM2835_LIB)
	LIB_RPI += -lbcm2835 -lm 
else ifeq ($(USELIB_RPI), USE_WIRINGPI_LIB)
	LIB_RPI += -lwiringPi -lm 
else ifeq ($(USELIB_RPI), USE_LGPIO_LIB)
	LIB_RPI += -llgpio -lm 
else ifeq ($(USELIB_RPI), USE_DEV_LIB)
	LIB_RPI += -lgpiod -lm 
endif
DEBUG_RPI = -D $(USELIB_RPI) -D RPI

# Compiler and Linker Settings
CC            = gcc
CFLAGS        = -I$(DIR_Config) -I$(DIR_EPD) -I$(DIR_FONTS) -I$(DIR_GUI) -O2 -Wall
TARGET        = epd

# test
# MSG = -g -O -ffunction-sections -fdata-sections -Wall
# CFLAGS += $(MSG) -D $(EPD)

# Phony Targets
.PHONY: all clean rebuild RPI

RPI:RPI_DEV RPI_epd 

all: $(TARGET)

$(TARGET): $(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) -o $(TARGET)

# # Rule to compile source files to object files
# $(DIR_BIN)/%.o: %.c
# 	$(shell mkdir -p $(DIR_BIN))
# 	$(CC) $(CFLAGS) -c $< -o $@


${DIR_BIN}/%.o: %.c
	$(CC) $(CFLAGS) -c	$< -o $@ -I $(DIR_Config) -I $(DIR_GUI) -I $(DIR_EPD) $(DEBUG)
	
${DIR_BIN}/%.o:$(DIR_EPD)/%.c
	$(CC) $(CFLAGS) -c	$< -o $@ -I $(DIR_Config) $(DEBUG)

${DIR_BIN}/%.o:$(DIR_FONTS)/%.c 
	$(CC) $(CFLAGS) -c	$< -o $@ $(DEBUG)
	
${DIR_BIN}/%.o:$(DIR_GUI)/%.c
	$(CC) $(CFLAGS) -c	$< -o $@ -I $(DIR_Config) $(DEBUG)

RPI_epd:${OBJ_O}
	echo $(@)
	$(CC) $(CFLAGS) -D RPI $(OBJ_O) $(RPI_DEV_C) -o $(TARGET) $(LIB_RPI) $(DEBUG)
	
RPI_DEV:
	$(CC) $(CFLAGS) $(DEBUG_RPI) -c	 $(DIR_Config)/dev_hardware_SPI.c -o $(DIR_BIN)/dev_hardware_SPI.o $(LIB_RPI) $(DEBUG)
	$(CC) $(CFLAGS) $(DEBUG_RPI) -c	 $(DIR_Config)/RPI_gpiod.c -o $(DIR_BIN)/RPI_gpiod.o $(LIB_RPI) $(DEBUG)
	$(CC) $(CFLAGS) $(DEBUG_RPI) -c	 $(DIR_Config)/DEV_Config.c -o $(DIR_BIN)/DEV_Config.o $(LIB_RPI) $(DEBUG)


# Clean the project
clean:
	rm -f $(DIR_BIN)/*.o $(TARGET)

# clean and then builds project
rebuild: clean all
