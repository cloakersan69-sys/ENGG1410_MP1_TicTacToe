#include <stdio.h>
#include "board.h"
#include "input.h"



int main() {

    int size;
    char board[MAX_SIZE][MAX_SIZE];
    int gameType;


    printf("== Tic-Tac-Toe ==\n");
    printf("Board Size (3-10): ");
    size = read_int();
    while (size < 3 || size > 10) {
        printf("Please enter a number within the range: ");
        size = read_int();
    }
    
    
    printf("1) Two players\n" "2) Play against the computer\n" "Mode: ");
    gameType = read_int();
    while (gameType < 1 || gameType > 2) {
        printf("Please enter a number within the range: ");
        gameType = read_int();
    }

    
    board_init(board, size);

    board_print(board, size);
    printf("\n");

    


}