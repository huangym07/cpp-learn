# compilation configure
CC = g++
CXXFLAGS = -Wextra -Wall -Werror -MMD -MP

ifdef DEBUG
	CXXFLAGS += -O0 -g
else
	CXXFLAGS += -O2
endif

SRC_DIR = $(abspath ./src)
SRCS ?= $(shell find $(SRC_DIR) -name "*.cpp")

BUILD_DIR = $(abspath ./build)
OBJ_DIR = $(BUILD_DIR)/obj_dir

$(shell mkdir -p $(OBJ_DIR))

OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(SRCS)))))
BIN = $(BUILD_DIR)/run

-include $(OBJS:.o=.d)

run: $(BIN)
	$<

$(BIN): $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

###############################################################################

.PHONY: run clean

clean: 
	rm -rf $(BUILD_DIR)
