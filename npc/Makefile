all:
	@echo "Write this Makefile by your self."

include $(NVBOARD_HOME)/scripts/nvboard.mk

TOPNAME = top
VSRCS = vsrc/top.v
CSRCS = csrc/main.cpp $(AUTO_BIND)
TARGET = $(OBJ_DIR)/V$(TOPNAME) 
NXDC_FILES = constr/top.nxdc
AUTO_BIND = build/auto_bind.cpp

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir

VERILATOR = verilator
VERILATOR_CFLAGS = --cc --exe --build --trace-fst -j 0 -Wall

$(AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $< $@

INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME=V$(TOPNAME)

sim: $(TARGET)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	./$(TARGET)

$(TARGET): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
	--top-module $(TOPNAME) $^ \
	$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
	--Mdir $(OBJ_DIR) --exe -o $(abspath $(TARGET))

clean:
	rm -rf $(BUILD_DIR)

.PHONY: sim clean

include ../Makefile
