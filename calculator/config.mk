# config.mk
TARGET := calculator
PROFILE ?= debug

NPROC := $(shell nproc)
MAKEFLAGS += -j$(NPROC)

SRC_DIR := ./src
INC_DIR := ./inc ./libcalc/inc/
BUILD_DIR := ./build
OBJ_FILES_DIR := objs
TARGETS_DIR := target

STATIC_LIBS := calc
STATIC_LIB_DIR := ./libcalc
STATIC_LIB_SRC := ./libcalc/src
STATIC_LIB_INC := ./libcalc/inc

CC ?= clang
CCFLAGS_BASE := -std=c17 
WFLAGS :=-Wall -Wextra -Wpedantic -Werror
DFLAGS := -O2 -ggdb3
LDFLAGS ?=
LIBS := m # libm
DEPFLAGS := -MMD -MP -MF
