#include "board.h"
#include <stdio.h>

// William Bailey 1387068.
// Wrote the functions for board_print, board_has_winner, and board_is_full.

/** Myles Leclerc 1391784
 * Wrote the board_init, move_is_valid, and ai_move functions.
 * 
 * (Code description)*/


void board_init(char board[MAX_SIZE][MAX_SIZE], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j]=EMPTY;
        }
        
    }
    
}

void board_print(char board[MAX_SIZE][MAX_SIZE], int n){

    /*Creates the initial formatting and grid numbers needed 
    For the board*/
    printf(" ");
    for (int c = 0; c < n; c++) {
        if (c == 0) {
        printf("%5d", c);
        }
        else if (c >= 0) {
        printf("%6d", c );
        }
    }
    
    // Starts printing out the rows needed
    for (int r = 0; r < n; r++) {
        printf("\n%2d ", r);
        for (int c = 0; c < n; c++) {
            char cell = board[r][c]; //Initial Formatting needed for the rows
            printf("%3c", cell);
            if (c < n - 1) printf("%3s", "|");   
            if (c == n - 1) printf("%3s", " ");
        }
        /* Prints seperator medians every row in the grid,
        doesn't fill outside grid. */
        if (r < n - 1) {
            printf("\n");
            for (int c = 0; c < n; c++) {
                if (c == 0) printf("%9s", "+----+");
                else if (c > 0) printf("%6s", "-----+");
                else if (r == n) printf("%6s", " ");
            }
        }
    }
    printf("\n");
}

int move_is_valid(char board[MAX_SIZE][MAX_SIZE], int n, int row, int col){
    if (row < 0 || row >= n || col < 0 || col >= n) {
        return 0;
    }
    return board[row][col] == EMPTY;
}

int board_has_winner(char board[MAX_SIZE][MAX_SIZE], int n, char mark){
    //returns 1 if win and 0 if none
    int winningCheck;

    //checks rows
    for (int r = 0; r < n; r++) {
       
        winningCheck = 1;
        for (int c = 0; c < n; c++) {
            if (board[r][c] != mark) {
                winningCheck = 0;
                break;
            }
        }
        if (winningCheck == 1) return 1;
    }
    //check columns
    for (int c = 0; c < n; c++) {
        
        winningCheck = 1;
        for (int r = 0; r < n; r++) {
            if (board[r][c] != mark){
                winningCheck = 0;
                break;
            }
        }
        if (winningCheck == 1) return 1;
    }
    
    //check main diagonal
    winningCheck = 1;
    for (int r = 0; r < n; r++)
    {
        if (board[r][r]!=mark){
            winningCheck=0;
            break;
        }
    }
    if (winningCheck == 1) return 1;
    //check other diagonal
    winningCheck = 1;
    for (int r = 0; r < n; r++)
    {   /* Checks the other diagonal by subtracting total board size by 1 and,
        subtracting the current row index to get the correct column index for each row. */
        if (board[r][n-1-r]!=mark){
            winningCheck=0;
            break;
        }
    }
    if (winningCheck == 1) return 1;
    return 0;
    
}

int board_is_full(char board[MAX_SIZE][MAX_SIZE], int n){
    int r;
    int c;

    /*Checks if all cells in the board are empty by iterating through each column once per row.
    Returns 0 is anything remains empty, if not returns 1 */
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            if (board[r][c] == EMPTY) {
                return 0;
            }
        }

    }
    return 1;

}

void ai_move(char board[MAX_SIZE][MAX_SIZE], int n, char ai_mark, char human_mark){
    //Take a win if ones available
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c]==EMPTY){
                board[r][c] = ai_mark;
                if (board_has_winner(board,n,ai_mark)){return;}
                board[r][c] = EMPTY;
            }
        }
    }
    //Block any winning cells of the opponent
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c]==EMPTY){
                board[r][c]=human_mark;
                if (board_has_winner(board,n,human_mark)){
                    board[r][c]=ai_mark;
                    return;
                }
                board[r][c]=EMPTY;
            }
        }
    }
    //Make the move on the first cell that isn't empty
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c]==EMPTY){
                board[r][c]=ai_mark;
                return;
            }
        }
    }
}