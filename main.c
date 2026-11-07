#include <stdio.h>
#include "board.h"
#include "input.c"
#include "input.h"
#include "board.c"


int main() {

    int size;
    char board[MAX_SIZE][MAX_SIZE];
    int gameType;


    printf("== Tic-Tac-Toe ==\n");
    printf("Board Size (3-10): ");
    size = read_int();

    printf("1) Two players\n" "2) Play against the computer\n" "Mode: ");
    gameType = read_int();

    while (read_char() != 1) {
        board_init(board, size);

        board_print(board, size);

    }


}