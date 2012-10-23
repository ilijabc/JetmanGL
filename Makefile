#################################################################################
# Project: Jetman Game
# Author: Ilija Djukic
#################################################################################

OUT_DIR := Out
OBJ_DIR := $(OUT_DIR)/obj
ONAME := $(OUT_DIR)/Jetman

# Default target is linux
ifndef ($(TARGET))
	TARGET := linux
endif

#################################################################################
# Source files
#################################################################################

include Files.mk

SRCS := \
	$(SRC_FRAMEWORK_GAME) \
	$(SRC_FRAMEWORK_GLPLUS) \
	$(SRC_FRAMEWORK_ALPLUS) \
	$(SRC_EXTERNAL_BOX2D) \
	$(SRC_EXTERNAL_NANOSVG) \
	$(SRC_EXTERNAL_TINYXML) \
	$(SRC_EXTERNAL_INIPARSER)

#SRCS += $(SRC_PACKAGE_ALIEN)
SRCS += $(SRC_PACKAGE_TEST)

#################################################################################
# Compiler settings
#################################################################################

INC_PATHS := -ISource/External -ISource/Frameworks
LIB_PATHS := 
LIBS := -lglfw

ifeq ($(BUILD),debug)
	OPT := -g -DDEBUG
else
	OPT := -Wall -O2
endif

#################################################################################
# Target settings
#################################################################################

ifeq ($(TARGET),linux)
	CC := gcc
	CPP := g++
	RMDIR := rm -rf
	MKDIR := mkdir -p
	LIBS += -lm -ldl -lGL -lGLU -lXrandr
endif

ifeq ($(TARGET),win32-mingw)
	CC := gcc
	CPP := g++
	RMDIR := rm -rf
	MKDIR := mkdir -p
	LIBS += -lgdi32 -lglu32 -lopengl32
	SRC_RES := Source/Resources/resource.rc
endif

#################################################################################
# Build rules
#################################################################################

CFLAGS := $(OPT) $(INC_PATHS) $(LIB_PATHS)
OBJS := $(foreach file, $(SRCS), $(OBJ_DIR)/$(strip $(basename $(file))).o)
RES := $(foreach file, $(SRC_RES), $(OBJ_DIR)/$(strip $(basename $(file))).res)

$(OBJ_DIR)/%.res: %.rc
	@echo Win32 Resource
	@-$(MKDIR) "$(@D)"
	@windres.exe -i $< -J rc -o $@ -O coff

$(OBJ_DIR)/%.o: %.cpp
	@echo Compiling $<
	@-$(MKDIR) "$(@D)"
	@$(CPP) -c $(CFLAGS) $(DEFINES) -o $@ $<

$(OBJ_DIR)/%.o:  %.c
	@echo Compiling $<
	@-$(MKDIR) "$(@D)"
	@$(CC) -c $(CFLAGS) $(DEFINES) -o $@ $<

#################################################################################
# Build rules
#################################################################################

all: info help

info:
	@echo ' ======================='
	@echo '  OUTPUT=$(ONAME)'
	@echo '  TARGET=$(TARGET)'
	@echo '  BUILD=$(BUILD)'
	@echo ' ======================='

build: info $(OBJS) $(RES)
	@echo 'Building $(ONAME)'
	@$(CPP) $(CFLAGS) -o $(ONAME) $(OBJS) $(RES) $(LIBS)
	@echo 'Finished building target: $(ONAME)'

clean:
	-$(RMDIR) $(OUT_DIR)
	@echo 'Intermediate files removed'

run: build
	./$(ONAME)

help:
	@echo " "
	@echo " -----------------------------------------------------------------------------"
	@echo " Usage:          make <rule> TARGET=<target> BUILD=<build>"
	@echo " "
	@echo " <rule>       :  build, clean, help                (default: help)"
	@echo " <target>     :  linux, win32-mingw, win32-msys    (default: linux)"
	@echo " <build>      :  release, debug                    (default: release)"
	@echo " -----------------------------------------------------------------------------"
