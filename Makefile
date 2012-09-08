#################################################################################
# Project: Jetman Game
# Author: Ilija Djukic
#################################################################################

OUT_DIR := Out
OBJ_DIR := $(OUT_DIR)/obj
ONAME := $(OUT_DIR)/Jetman

#################################################################################
# Source files
#################################################################################

SRC_GAME := \
	Source/Game/GameApp.cpp \
	Source/Game/GameLevel.cpp \
	Source/Game/GameMain_GLFW.cpp \
	Source/Game/GameObject.cpp

SRC_GLPLUS := \
	Source/GLPlus/BMFont.cpp \
	Source/GLPlus/GLCamera.cpp \
	Source/GLPlus/GLFont.cpp \
	Source/GLPlus/GLMaterial.cpp \
	Source/GLPlus/GLMath.cpp \
	Source/GLPlus/GLModel.cpp \
	Source/GLPlus/GLNode.cpp \
	Source/GLPlus/GLParticleSystem.cpp \
	Source/GLPlus/GLTexture.cpp \
	Source/GLPlus/GLView.cpp \
	Source/GLPlus/stb_image.c

SRC_BOX2D := \
	Source/Box2D/Collision/b2BroadPhase.cpp \
	Source/Box2D/Collision/b2CollideCircle.cpp \
	Source/Box2D/Collision/b2CollideEdge.cpp \
	Source/Box2D/Collision/b2CollidePolygon.cpp \
	Source/Box2D/Collision/b2Collision.cpp \
	Source/Box2D/Collision/b2Distance.cpp \
	Source/Box2D/Collision/b2DynamicTree.cpp \
	Source/Box2D/Collision/b2TimeOfImpact.cpp \
	Source/Box2D/Collision/Shapes/b2ChainShape.cpp \
	Source/Box2D/Collision/Shapes/b2CircleShape.cpp \
	Source/Box2D/Collision/Shapes/b2EdgeShape.cpp \
	Source/Box2D/Collision/Shapes/b2PolygonShape.cpp \
	Source/Box2D/Common/b2BlockAllocator.cpp \
	Source/Box2D/Common/b2Draw.cpp \
	Source/Box2D/Common/b2Math.cpp \
	Source/Box2D/Common/b2Settings.cpp \
	Source/Box2D/Common/b2StackAllocator.cpp \
	Source/Box2D/Common/b2Timer.cpp \
	Source/Box2D/Dynamics/b2Body.cpp \
	Source/Box2D/Dynamics/b2ContactManager.cpp \
	Source/Box2D/Dynamics/b2Fixture.cpp \
	Source/Box2D/Dynamics/b2Island.cpp \
	Source/Box2D/Dynamics/b2World.cpp \
	Source/Box2D/Dynamics/b2WorldCallbacks.cpp \
	Source/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
	Source/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
	Source/Box2D/Dynamics/Contacts/b2CircleContact.cpp \
	Source/Box2D/Dynamics/Contacts/b2Contact.cpp \
	Source/Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
	Source/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
	Source/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
	Source/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
	Source/Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
	Source/Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2GearJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2Joint.cpp \
	Source/Box2D/Dynamics/Joints/b2MouseJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2RopeJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2WeldJoint.cpp \
	Source/Box2D/Dynamics/Joints/b2WheelJoint.cpp \
	Source/Box2D/Rope/b2Rope.cpp

SRC_OTHER := \
	Source/NanoSVG/nanosvg.c \
	Source/TinyXML/tinyxml2.cpp \
	Source/iniParser/dictionary.c \
	Source/iniParser/iniparser.c

SRCS := $(SRC_GAME) $(SRC_GLPLUS) $(SRC_BOX2D) $(SRC_OTHER)

#################################################################################
# Compiler settings
#################################################################################

INC_PATHS := -ISource
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
	LIBS += -lm -ldl -lGL -lGLU
endif

ifeq ($(TARGET),win32-mingw)
	CC := gcc
	CPP := g++
	RMDIR := rmdir /S /Q
	MKDIR := mkdir
	LIBS += -lgdi32 -lglu32 -lopengl32
	SRC_RES := Source/Resources/resource.rc
endif

ifeq ($(TARGET),win32-msys)
	CC := gcc
	CPP := g++
	RMDIR := rm -rf
	MKDIR := mkdir
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

all: help

build: $(OBJS) $(RES)
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
	@echo " Usage:          make <rule> TARGET=<target>"
	@echo " "
	@echo " <rule>       :  build, clean, help"
	@echo " <target>     :  linux, win32-mingw, win32-msys"
	@echo " -----------------------------------------------------------------------------"
	@echo " $(TARGET)"