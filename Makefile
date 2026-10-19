# Makefile -- ENGG*1410 Mini-Project 1
# SUPPLIED FILE. Do not change this file.
#
#   make         builds ./tictactoe
#   make clean   removes ./tictactoe and the .o files

CC     = gcc
CFLAGS = -std=c11 -Wall -Wextra -g
OBJS   = main.o board.o input.o

tictactoe: $(OBJS)
	$(CC) $(CFLAGS) -o tictactoe $(OBJS)

main.o: main.c board.h input.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

input.o: input.c input.h
	$(CC) $(CFLAGS) -c input.c

.PHONY: clean
clean:
	rm -f tictactoe $(OBJS)
