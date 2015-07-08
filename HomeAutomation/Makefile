#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = HomeAutomation
#Set this to @ to keep the makefile quiet
SILENCE = @

TARGET_LIB = \
	lib/lib$(COMPONENT_NAME).a

TEST_TARGET = \
	$(COMPONENT_NAME)_tests

#--- Inputs ----#
PROJECT_HOME_DIR = .
ifeq "$(CPPUTEST_HOME)" ""
    CPPUTEST_HOME = ../CppUTest
endif
CPP_PLATFORM = Gcc

SRC_DIRS = \
    src\
#    src/*

# to pick specific files (rather than directories) use this:    
SRC_FILES = 

TEST_SRC_DIRS = \
    tests \
#    tests/*

MOCKS_SRC_DIRS = \
    mocks \

INCLUDE_DIRS =\
  .\
  include/\
  $(CPPUTEST_HOME)/include/\
  $(CPPUTEST_HOME)/include/Platforms/Gcc\
  tests/\
  mocks

#CPPUTEST_WARNINGFLAGS = -Wall -Werror -Wswitch-default 
CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default
CPPUTEST_WARNINGFLAGS += -Wconversion -Wswitch-enum 
CPPUTEST_CFLAGS += -std=c89
CPPUTEST_CFLAGS += -Wextra 
CPPUTEST_CFLAGS += -pedantic 
CPPUTEST_CFLAGS += -Wstrict-prototypes
CPPUTEST_USE_EXTENSIONS = Y
CPPUTEST_USE_GCOV = Y
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

