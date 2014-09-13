This archive contains demo project for use with Olimex GCCFD. Currently available is the following demo:

STM32-H103_flash		Blinks the LED on the STM32-H103 board, program in flash.
STM32-P103_flash		Blinks the LED on the STM32-P103 board, program in flash.
STM32-103STK_LCD_flash		Writes greeting text on the LCD of the STM32F103-STK board, then blinks LED on the board, program in flash.

Program code is compiled with Sourcery G++ program tools, that contains the complete GNU Toolchain for Cortex-M3 core, 
 available at: http://www.codesourcery.com/GNUToolchain/.
It is strongly recommended to install, if you want develop applications for Cortex-M3 CPU core.

Provided .CMD file - This Linker Script defines how the code and data emitted by the GNU C compiler and assembler are 
to be loaded into memory (code goes into FLASH, variables go into RAM). If you want develop applications for other development boards
based on Cortex-M3 CPU core, you should change MEMORY section and stack end according to memory map-look at the chapters for memory 
addressing and flash memory system in user manual of your board.

Another important file you need is .CFG file. In that file are specified commands for OpenOCD configuration.
The configuration file is used to specify on which ports the daemon listens for new connections, the JTAG interface used to connect to the target,
 the layout of the JTAG chain, the targets that should be debugged, and connected flashes.
For more information see http://openfacts.berlios.de/index-en.phtml?title=Open+On-Chip+Debugger

Each project has its own Makefile, where it is described how Sourcery G++ program tools to be invoked to compile source files.


Startup code is placed in main.c file, because Cortex-M3 family CPUs need an interrupt 
vector table to be declared.


			PROGRAM DEBUG
-----------------------------------------------------------------------------
1.Copy extracted "projects_STM32" directory in C:\gccfd
2. Switch to the Debug Perspective(Window->Show View->Debug)
3. Start OpenOCD program from Run -> External Tools -> OpenOCD (main.c should be the currently acive window!) 
4. Start the debugger from "Run->Open Debug Dialog->Embedded Debug(Cygwin)-><your prject debug profile>", "Debug"
5. Enjoy the demo.