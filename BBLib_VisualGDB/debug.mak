#Generated by VisualGDB (http://visualgdb.com)
#DO NOT EDIT THIS FILE MANUALLY UNLESS YOU ABSOLUTELY NEED TO
#USE VISUALGDB PROJECT PROPERTIES DIALOG INSTEAD

BINARYDIR := Debug

#Toolchain
CC := C:/SysGCC/beaglebone/bin/arm-linux-gnueabihf-gcc.exe
CXX := C:/SysGCC/beaglebone/bin/arm-linux-gnueabihf-g++.exe
LD := $(CXX)
AR := C:/SysGCC/beaglebone/bin/arm-linux-gnueabihf-ar.exe
OBJCOPY := C:/SysGCC/beaglebone/bin/arm-linux-gnueabihf-objcopy.exe

#Additional flags
PREPROCESSOR_MACROS := DEBUG
INCLUDE_DIRS := 
LIBRARY_DIRS := 
LIBRARY_NAMES := pthread
ADDITIONAL_LINKER_INPUTS := 
MACOS_FRAMEWORKS := 
LINUX_PACKAGES := 

CFLAGS := -ggdb -ffunction-sections -O0
CXXFLAGS := -ggdb -ffunction-sections -O0 -std=c++0x
ASFLAGS := 
LDFLAGS := -Wl,-gc-sections
COMMONFLAGS := -lpthread

START_GROUP := -Wl,--start-group
END_GROUP := -Wl,--end-group

#Additional options detected from testing the toolchain
USE_DEL_TO_CLEAN := 1
CP_NOT_AVAILABLE := 1
IS_LINUX_PROJECT := 1
