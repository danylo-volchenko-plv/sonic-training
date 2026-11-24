# rule.mk
LINK.o = $(CC)

$(TARGET_DIR) $(DEP_DIR) $(OBJ_DIR) $(LIB_OBJ_DIR) $(LIB_DEP_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	@echo "[compiling $<]"
	$(CC) -c $(CCFLAGS) $(DEPFLAGS) \
		$(DEP_DIR)/$*.d $< -o $@

$(LIB_OBJ_DIR)/%.o : $(DYN_LIB_SRC)/%.c | $(LIB_OBJ_DIR) $(LIB_DEP_DIR)
	@echo "[compiling lib $<]"
	$(CC) -c $(CCFLAGS) $(addprefix -I,$(LIB_INCS)) -fPIC  $(DEPFLAGS) \
		$(LIB_DEP_DIR)/$*.d $< -o $@

$(DYN_LIB_FILE): $(LIB_OBJS) | $(TARGET_DIR)
	@echo "[linking shared lib $@]"
	$(CC) -shared $(addprefix -I,$(DYN_LIB_INC)) $^ -o $@
	@echo "If no install target is run, execute the following:\n \
				export LD_LIBRARY_PATH=$$(pwd):\$$LD_LIBRARY_PATH"

.PHONY: clean
clean:
	@echo "[cleaning project]"
	@rm -rf $(CLEAN_FILES)
	@echo "clean complete"

ifneq ($(MAKECMDGOALS),clean)
	-include $(DEPS)
endif
