CC = gcc
CFLAGS = -Wall -Wextra -g

STATIC_LIB = libstrutils.a
SHARED_LIB = libstrutils.so

BUILD_DIR = build

.PHONY: all static shared clean mkdir_build

all: static shared

static: mkdir_build $(BUILD_DIR)/$(STATIC_LIB)
	$(CC) main.c -L$(BUILD_DIR) -lstrutils -o $(BUILD_DIR)/main_static

shared: mkdir_build $(BUILD_DIR)/$(SHARED_LIB)
	$(CC) main.c -L$(BUILD_DIR) -lstrutils -o $(BUILD_DIR)/main_shared

$(BUILD_DIR)/$(STATIC_LIB): bstrutils.c strutils.h
	$(CC) $(CFLAGS) -c bstrutils.c -o $(BUILD_DIR)/strutils.o
	ar rcs $@ $(BUILD_DIR)/strutils.o

$(BUILD_DIR)/$(SHARED_LIB): bstrutils.c strutils.h
	$(CC) $(CFLAGS) -fPIC -shared bstrutils.c -o $@

mkdir_build:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
