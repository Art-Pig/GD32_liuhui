###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = AT89C51
COMPILER = "Keil for 8051"
TARGET = Debug
SHELL = C:\windows\system32\cmd.exe

## Tools general options
CCFLAGS=ROM(COMPACT) BROWSE DEBUG CODE OBJECTEXTEND PREPRINT

## Processing Tools
CC=C51.exe
LD=BL51.exe
ASM=A51.exe
#  E:/201608单片机应用技术（C51语言）教学课件/第7章 单片机与中断系统接口技术/【例举7_1】外部中断/AT89C51/Debug/Debug.OMF: TOOL=LD
#     E:/201608单片机应用技术（C51语言）教学课件/第7章 单片机与中断系统接口技术/【例举7_1】外部中断/AT89C51/Debug/main.OBJ: TOOL=CC
#        E:/201608单片机应用技术（C51语言）教学课件/第7章 单片机与中断系统接口技术/【例举7_1】外部中断/AT89C51/main.c

# Build tree:
all:	Debug

Debug:	Debug.OMF

Debug.OMF:	main.OBJ 
	"C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\Tools\MAKE\RunTool.exe" --good-exits=0,1 --executable=$(LD) "main.OBJ" TO "Debug.OMF" $(LDFLAGS) 

main.OBJ:	../main.c 
	"C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\Tools\MAKE\RunTool.exe" --good-exits=0,1 --executable=$(CC) "..\main.c" $(CCFLAGS)  OBJECT("main.OBJ")

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Debug.M51
	rm -rf ./main.lst
	rm -rf ./main.I

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.OMF
	rm -rf main.OBJ
