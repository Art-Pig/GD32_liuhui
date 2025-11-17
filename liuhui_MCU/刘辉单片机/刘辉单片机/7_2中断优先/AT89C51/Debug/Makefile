###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = AT89C51
COMPILER = "Keil for 8051"
TARGET = Debug
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
CCFLAGS=ROM(COMPACT) BROWSE DEBUG CODE OBJECTEXTEND PREPRINT

## Processing Tools
CC=C51.exe
LD=BL51.exe
ASM=A51.exe
#  C:/Users/66/Desktop/我单片机(韩教材)2021.3-2021.7/韩克PPT教案/第7章 单片机与中断系统接口技术/【例举7_3】中断优先/AT89C51/Debug/Debug.OMF: TOOL=LD
#     C:/Users/66/Desktop/我单片机(韩教材)2021.3-2021.7/韩克PPT教案/第7章 单片机与中断系统接口技术/【例举7_3】中断优先/AT89C51/Debug/main.OBJ: TOOL=CC
#        C:/Users/66/Desktop/我单片机(韩教材)2021.3-2021.7/韩克PPT教案/第7章 单片机与中断系统接口技术/【例举7_3】中断优先/AT89C51/main.c

# Build tree:
all:	Debug

Debug:	Debug.OMF

Debug.OMF:	main.OBJ 
	"..\..\..\..\..\..\..\..\..\Program Files\Labcenter Electronics\Proteus 8 Professional\Tools\MAKE\RunTool.exe" --good-exits=0,1 --executable=$(LD) "main.OBJ" TO "Debug.OMF" $(LDFLAGS) 

main.OBJ:	../main.c 
	"..\..\..\..\..\..\..\..\..\Program Files\Labcenter Electronics\Proteus 8 Professional\Tools\MAKE\RunTool.exe" --good-exits=0,1 --executable=$(CC) "..\main.c" $(CCFLAGS)  OBJECT("main.OBJ")

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Debug.M51
	rm -rf ./main.lst
	rm -rf ./main.I

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.OMF
	rm -rf main.OBJ
