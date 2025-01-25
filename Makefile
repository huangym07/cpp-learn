# Some common configs for submodule.


# Compiler
CC = g++


# CXX flags
CXXSTD = -std=c++17

CXXFLAGS = $(CXXSTD) -MMD -MP
CXXFLAGS += $(addprefix -I, $(INC_PATH))

# Debug
ifeq ($(MODE), debug)
	CXXFLAGS += -ggdb -O0
else
	CXXFLAGS += -O2
endif

# Warning
ifeq ($(WARN), all)
	CXXFLAGS += -Wextra -Wall -Werror
endif

# Inlcude path
INC_PATH = $(abspath ../include/)


# Preview markdown
readme_makedown_preview: README.html
	xdg-open README.html

README.html: README.md
	pandoc README.md -o README.html
clean_README_html:
	rm README.html

.PHONY: readme_makedown_preview clean_README_html

