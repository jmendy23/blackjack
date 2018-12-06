# FileName: Makefile
# Author: Jake Mendenhall
# Due Date: 2/23/16
# Description: makefile for main.c and stack.c

# Compiler options:
 CFLAGS=-c -Wextra

all: gameExe

gameExe: main.o stack.o
	$(CC) main.c stack.c -o gameExe

main: main.c
	$(CC) $(CFLAGS) main.c

stack: stack.c
	$(CC) $(CFLAGS) stack.c

clean:
	rm -rf *.o gameExe

