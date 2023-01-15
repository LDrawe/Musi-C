IDIR = ./include
CC = gcc
CFLAGS = -Wall -Isrc/include
CPPFLAGS = -Iinclude -MMD -MP
SRC = $(wildcard src/*.c)
DEPS = $(IDIR)/utils.h
BIN = ./src/bin
# OBJ = src/main.c

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

all: src/main.c src/research.c
	$(CC) -o $(BIN)/MusiC src/main.c $(CFLAGS)
	$(CC) src/research.c $(CFLAGS) -o $(BIN)/research

main: src/main.c
	$(CC) -o $(BIN)/MusiC src/main.c $(CFLAGS)

research: src/research.c
	$(CC) src/research.c $(CFLAGS) -o $(BIN)/research