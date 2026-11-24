# config.mk
TARGET := text-format
PROFILE ?= debug

NPROC := $(shell nproc)
MAKEFLAGS += -j$(NPROC)

SRC_DIR := ./src
INC_DIR := ./inc ./libconvert/inc/
BUILD_DIR := ./build
OBJ_FILES_DIR := objs
TARGETS_DIR := target

DYN_LIBS := convert
DYN_LIB_DIR := ./libconvert/
DYN_LIB_SRC := ./libconvert/src
DYN_LIB_INC := ./libconvert/inc

CC ?= clang
CCFLAGS_BASE := -std=c17 
WFLAGS :=-Wall -Wextra -Wpedantic -Werror
DFLAGS := -O2 -ggdb3
LDFLAGS ?=
EXT_LIBS := 
DEPFLAGS := -MMD -MP -MF
