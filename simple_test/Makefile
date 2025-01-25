# include other Makefiles
include ./../Makefile


# Build
BUILD_DIR = $(abspath ./build)

$(shell mkdir -p $(BUILD_DIR))

SINGLE_BIN = $(addprefix $(BUILD_DIR)/, $(patsubst %.cpp, %_executable, $(SINGLE_SRC)))

# Source files
SINGLE_SRC ?= main.cpp


# Target
default: $(SINGLE_BIN)

run: $(SINGLE_BIN)
	$(SINGLE_BIN)

$(SINGLE_BIN): $(SINGLE_SRC)
	$(CC) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default run clean
