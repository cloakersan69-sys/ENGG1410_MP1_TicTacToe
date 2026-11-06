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

    printf(" ");
    for (int c = 0; c < n; c++) {
        printf("%4d", c);
    }
    printf("\n");
    for (int r = 0; r < n; r++) {
        printf("%2d ", r);
        for (int c = 0; c < n; c++) {
            char cell = ' ';
            if ()
            
            printf(" %c ", board[r][c]);

        }
    printf("\n");
    }
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

}

int board_is_full(char board[MAX_SIZE][MAX_SIZE], int n){

}

void ai_move(char board[MAX_SIZE][MAX_SIZE], int n, char ai_mark, char human_mark){

}