# rule.mk
LINK.o = $(CC)
AR ?= ar
ARFLAGS ?= rcs

$(TARGET_DIR) $(DEP_DIR) $(OBJ_DIR) $(LIB_OBJ_DIR) $(LIB_DEP_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	@echo "compiling $<"
	$(CC) -c $(CCFLAGS) $(DEPFLAGS) \
		$(DEP_DIR)/$*.d $< -o $@

$(LIB_OBJ_DIR)/%.o : $(STATIC_LIB_SRC)/%.c | $(LIB_OBJ_DIR) $(LIB_DEP_DIR)
	@echo "compiling lib $<"
	$(CC) -c $(CCFLAGS) $(DEPFLAGS) \
		$(LIB_DEP_DIR)/$*.d $< -o $@

ifneq ($(strip $(STATIC_LIBS)),)
$(STATIC_LIB_FILE): $(LIB_OBJS) | $(TARGET_DIR)
	@echo "archiving $@"
	$(AR) $(ARFLAGS) $@ $(LIB_OBJS)
endif

.PHONY: clean
clean:
	@echo "cleaning project"
	@rm -rf $(CLEAN_FILES)
	@echo "clean complete"

ifneq ($(MAKECMDGOALS),clean)
	-include $(DEPS)
endif
