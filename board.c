#include "board.h"
#include <stdio.h>

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
    
    // Starts printing out the rows needs
    for (int r = 0; r < n; r++) {
        printf("\n%2d ", r);
        for (int c = 0; c < n; c++) {
            char cell = board[r][c]; //Initial Formatting needed for the rows
            cell = ' ';
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
    if (!(((row>=1)&&(row<=n))&&((col>=1)&&(col<=n)))) //Checks if the row and column cant be within the bounds of the table
    {
        return 0;
    }

    if (board[row-1][col-1]==EMPTY){
        return 1;
    }else{
        return 0;
    }
    
}

int board_has_winner(char board[MAX_SIZE][MAX_SIZE], int n, char mark){
    
    int winningCheck;

    /*checks rows*/
    for (int r = 0; r < n; r++) {
       
        winningCheck = 1;
        for (int c = 0; c < n; c++) {
            if (board[r][c] != mark) {
                winningCheck = 0;
                return 0;
                
            }
        }
    }
    if (winningCheck == 1) return 1;

    for (int c = 0; c < n; c++) {
        
        winningCheck = 1;
        for (int r = 0; r < n; r++) {
            if (board[r][c] != mark){
            winningCheck = 0;
            return 0;
            }
        }
    }
    if (winningCheck == 1) return 1;

    for (int r = 0; r < n; r++) {
    
        if (board[r][r] != mark) {
        return 0;
        }
        else if (board[r][n - 1 - r] != mark) {
        return 0;

        }
        else {
        winningCheck = 1;
        break;
        }
    }
    return 1;
    
}

int board_is_full(char board[MAX_SIZE][MAX_SIZE], int n){
    int r;
    int c;

    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            if (board[r][c] != EMPTY) {
                return 1;
            }
            else {
            break;
            }
        }

    }
    return 0;

}

void ai_move(char board[MAX_SIZE][MAX_SIZE], int n, char ai_mark, char human_mark){

}