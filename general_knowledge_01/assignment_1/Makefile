CC = gcc
CFLAGS = -Wall -Wextra -g

STATIC_LIB = libstrutils.a
SHARED_LIB = libstrutils.so

.PHONY: all static shared clean

all: static shared

static: $(STATIC_LIB)
	$(CC) main.c -L. -lstrutils -o main_static

shared: $(SHARED_LIB)
	$(CC) main.c -L. -lstrutils -o main_shared

$(STATIC_LIB): strutils.c strutils.h
	$(CC) $(CFLAGS) -c strutils.c -o strutils.o
	ar rcs $@ strutils.o

$(SHARED_LIB): strutils.c strutils.h
	$(CC) $(CFLAGS) -fPIC -shared strutils.c -o $@

clean:
	rm -f *.o *.a *.so main_static main_shared
