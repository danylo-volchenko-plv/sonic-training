# makefile
include config.mk

SRCS := $(shell find $(SRC_DIR) -name *.c)
INCS := $(shell find $(INC_DIR) -name *.h)

LIB_SRCS := $(if $(strip $(DYN_LIBS)),$(shell find $(DYN_LIB_SRC) -name '*.c'),)
LIB_INCS := $(if $(strip $(DYN_LIBS)),$(shell find $(DYN_LIB_INC) -name '*.h'),)

OBJ_DIR := $(BUILD_DIR)/$(OBJ_FILES_DIR)/$(PROFILE)
TARGET_DIR := $(BUILD_DIR)/$(TARGETS_DIR)/$(PROFILE)
DEP_DIR := $(BUILD_DIR)/deps
LIB_OBJ_DIR := $(OBJ_DIR)/dl
LIB_DEP_DIR := $(DEP_DIR)/dl

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(patsubst $(SRC_DIR)/%.c,$(DEP_DIR)/%.d,$(SRCS))
LIB_OBJS := $(patsubst $(_LIB_SRC)/%.c,$(LIB_OBJ_DIR)/%.o,$(LIB_SRCS))
LIB_DEPS := $(patsubst $(_LIB_SRC)/%.c,$(LIB_DEP_DIR)/%.d,$(LIB_SRCS))

DYN_LIB_NAME := $(firstword $(DYN_LIBS))
DYN_LIB_FILE := $(if $(DYN_LIB_NAME),$(TARGET_DIR)/lib$(DYN_LIB_NAME).so,)
CLEAN_FILES := $(BUILD_DIR) $(TARGET) release debug-*

DEPS += $(LIB_DEPS)
CLEAN_FILES += $(LIB_OBJ_DIR) $(LIB_DEP_DIR)

override CCFLAGS := $(CCFLAGS_BASE)
override CCFLAGS += $(addprefix -I, $(INC_DIR)) $(WFLAGS)
override LDFLAGS := $(addprefix -l,$(LIBS))

ifeq ($(PROFILE),release)
	override CCFLAGS += -march=native -O3 -flto
	override LDFLAGS += -march=native -O3 -flto
else
	override CCFLAGS += $(DFLAGS)
endif

.DEFAULT_GOAL := build
include rule.mk

ifneq ($(strip $(DYN_LIBS)),)
	override LDFLAGS := $(addprefix -L,$(TARGET_DIR)) $(addprefix -l,$(DYN_LIBS)) $(addprefix -l,$(LIBS))
endif

.PHONY: build banner
build: banner $(if $(filter release,$(PROFILE)),linter) $(OBJS) $(DYN_LIB_FILE) | $(TARGET_DIR)
	$(LINK.o) $(OBJS) -o $(TARGET_DIR)/$(TARGET) $(LDFLAGS)
ifdef STRIP
	@echo "[stripping] $(TARGET_DIR)/$(TARGET)"
	strip --strip-unneeded --preserve-dates $(TARGET_DIR)/$(TARGET)
endif
	@echo "[post-build] Symlinking"
	@ln -sfn $(TARGET_DIR) $(PROFILE)
	@ln -sfn $(TARGET_DIR)/$(TARGET) $(TARGET)
	@echo "[build complete] profile: $(PROFILE)"

banner:
	@echo "[building $(PROFILE) profile]"


.PHONY: all
all:
	@$(MAKE) PROFILE=release build
	@$(MAKE) PROFILE=debug build
	@$(MAKE) compdb

.PHONY: install
install:
	@$(MAKE) PROFILE=release build
ifneq ($(strip $(DYN_LIBS)),)
	@for lib in $(DYN_LIBS); do \
		install -Dm 0755 "$(TARGET_DIR)/lib$$lib.so" "$(PREFIX)/lib/lib$$lib.so"; \
	done
endif
	@install -Dm 0755 $(TARGET) $(PREFIX)/bin/$(TARGET)

.PHONY: compdb
compdb:
	@echo "generating compilation database"
	@command -v bear >/dev/null || { echo "Error: bear not found"; exit 1; }
	@mkdir -p $(BUILD_DIR)
	@bear --output $(BUILD_DIR)/compile_commands.json -- make PROFILE=release build -B
	@echo "[compdb complete]"

.PHONY: linter
linter:
	@echo "running linter"
	cppcheck --check-level=exhaustive --enable=all --inconclusive --verbose \
		--suppress=missingIncludeSystem --suppress=unusedFunction \
		$(addprefix -I,$(INC_DIR)) .

.PHONY: help
help:
	@echo "  build         : Build the project (default, uses PROFILE and SANITIZER)"
	@echo "  all           : Build release and all debug variants + compdb"
	@echo "  compdb        : Generate compile_commands.json (requires bear)"
	@echo "  linter        : Run cppcheck linter"
	@echo "  clean         : Remove all build artifacts"
	@echo "  help          : Show this help message"
	@echo "\nVariables:"
	@echo "  PROFILE       : debug (default) or release"
