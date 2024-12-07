CC = g++

CPPSTD = -std=c++17
CXXFLAGS = -Wall -Werror $(CPPSTD)

INC_PATH = .\include

ifeq ($(OS), Windows_NT)
	CLEAN_CMD = del
endif
ifeq ($(OS), Linux)
	CLEAN_CMD = rm -rf
endif

ifdef INC
	CXXFLAGS += $(addprefix -I, $(INC_PATH))
endif

ifdef DEBUG
	CXXFLAGS += -DDEBUG -g -O0
else
	CXXFLAGS += -O2
endif

SRC = .\src\main.cpp
BIN = .\build\cp.exe

default: run

run: $(BIN)
	$<

$(BIN): $(SRC)
	$(CC) $(CXXFLAGS) $< -o $@

.PHONY: default run clean test

test: 
	gcc .\src\test.c -o .\build\test.exe
	.\build\test.exe

clean:
	$(CLEAN_CMD) $(BIN)