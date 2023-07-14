
CC = gcc

SRC = $(wildcard sources/*.c)

.PHONY = .all .clean .run

all: .all

.all:

clean: .clean

.clean: pgmDraw
	rm pgmDraw

run: .run

.run: pgmDraw
	./$<
	make clean

pgmDraw:
	$(CC) -o $@ $@.c $(SRC)

