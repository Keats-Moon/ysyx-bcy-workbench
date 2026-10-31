all:
	@echo "Write this Makefile by your self."

TOP = top 
VSRCS = vsrc/top.v
CSRCS = csrc/main.cpp
TARGET = obj_dir/Vtop 
sim: $(TARGET)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	./$(TARGET)

$(TARGET): $(VSRCS) $(CSRCS)
	verilator --cc --exe --build --trace-fst -j 0 -Wall $(VSRCS) $(CSRCS)

.PHONY: sim

include ../Makefile
