NAME   = demoh103_blink_rom

CC      = arm-none-eabi-gcc
LD      = arm-none-eabi-ld -v
AR      = arm-none-eabi-ar
AS      = arm-none-eabi-as
CP      = arm-none-eabi-objcopy
OD		= arm-none-eabi-objdump

VPATH 	= lib lcd
  
CFLAGS  =  -I./ -c -fno-common -O0 -g -mcpu=cortex-m3 -mthumb 
AFLAGS  = -ahls -mapcs-32 -o crt.o
LFLAGS  = -Tstm_h103_blink_rom.cmd -nostartfiles
CPFLAGS = -Obinary
ODFLAGS	= -S

all: test

clean:
	-rm -f main.lst main.o main.out main.hex main.map stm32f10x_rcc.o stm32f10x_gpio.o stm32f10x_spi.o stm32f10x_lib.o
	-rm -f Lucida_Console_6_6x6.o drv_pcd8544_l.o drv_pcd8544.o

test: main.out
	@ echo "...copying"
	$(CP) $(CPFLAGS) main.out main.bin
	$(OD) $(ODFLAGS) main.out > main.list

main.out: main.o stm32f10x_rcc.o stm32f10x_gpio.o stm_h103_blink_rom.cmd stm32f10x_spi.o Lucida_Console_6_6x6.o drv_pcd8544_l.o drv_pcd8544.o
	@ echo "..linking"
	$(LD) $(LFLAGS) -o main.out stm32f10x_rcc.o stm32f10x_gpio.o main.o stm32f10x_spi.o Lucida_Console_6_6x6.o drv_pcd8544_l.o drv_pcd8544.o

stm32f10x_rcc.o: stm32f10x_rcc.c 
	@ echo ".compiling"
	 $(CC) $(CFLAGS) lib\stm32f10x_rcc.c 
	 
stm32f10x_gpio.o: stm32f10x_gpio.c
	@ echo ".compiling"
	 $(CC) $(CFLAGS) lib\stm32f10x_gpio.c 

stm32f10x_spi.o: stm32f10x_spi.c
	@ echo ".compiling"
	 $(CC) $(CFLAGS) lib\stm32f10x_spi.c 

	 
main.o: main.c
	@ echo ".compiling"
	 $(CC) $(CFLAGS) main.c
	 
	 
drv_pcd8544.o: drv_pcd8544.c
	@ echo ".compiling"
	 $(CC) $(CFLAGS) lcd\drv_pcd8544.c

drv_pcd8544_l.o: drv_pcd8544_l.c
	@ echo ".compiling"
	 $(CC) $(CFLAGS) lcd\drv_pcd8544_l.c

Lucida_Console_6_6x6.o: Lucida_Console_6_6x6.c
	@ echo ".compiling"
	 $(CC) $(CFLAGS) lcd\Lucida_Console_6_6x6.c