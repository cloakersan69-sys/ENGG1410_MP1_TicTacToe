/*
 * board.h -- ENGG*1410 Mini-Project 1
 *
 * SUPPLIED FILE. Do not change anything in this file.
 * Implement every function below in board.c.
 *
 * Rows and columns are numbered from 0 to n-1.
 */
#ifndef BOARD_H
#define BOARD_H

#define MIN_SIZE 3
#define MAX_SIZE 10
#define EMPTY ' '

/* Fill every cell of the n x n board with EMPTY. */
void board_init(char board[MAX_SIZE][MAX_SIZE], int n);

/* Print the board with row and column numbers so a player can
   identify any cell. */
void board_print(char board[MAX_SIZE][MAX_SIZE], int n);

/* Return 1 if (row, col) is on the board and the cell is EMPTY.
   Return 0 otherwise. */
int move_is_valid(char board[MAX_SIZE][MAX_SIZE], int n, int row, int col);

/* Return 1 if `mark` fills an entire row, an entire column, or
   either diagonal. Return 0 otherwise. */
int board_has_winner(char board[MAX_SIZE][MAX_SIZE], int n, char mark);

/* Return 1 if no cell is EMPTY. Return 0 otherwise. */
int board_is_full(char board[MAX_SIZE][MAX_SIZE], int n);

/* Make the computer's move: write `ai_mark` into one EMPTY cell.
   Order: (a) win if possible, (b) otherwise block `human_mark`,
   (c) otherwise any EMPTY cell.
   Only call this when the board is not full. */
void ai_move(char board[MAX_SIZE][MAX_SIZE], int n, char ai_mark, char human_mark);

#endif
