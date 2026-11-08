#include <stdio.h>
#include "board.h"
#include "input.h"



int main() {

    int size;
    char board[MAX_SIZE][MAX_SIZE];
    int xWins = 0, oWins = 0, draws = 0;
    int gameType;
    char redo, currentPlayer;
    int roundOver;

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

    do{
        currentPlayer='X';
        roundOver=0;
        board_init(board, size);
        while (!roundOver)
        {
            board_print(board,size);
            if (gameType == 2 && currentPlayer == 'O'){
                printf("Computer is moving...\n");
                ai_move(board, size, 'O', 'X');
            } else{
                int row,col;
                printf("\nPlayer %c choice row: ", currentPlayer);
                row = read_int();
                printf("\nPlayer %c choice column: ", currentPlayer);
                col = read_int();

                while (!move_is_valid(board, size, row, col)) {
                    if (row < 0 || row >= size || col < 0 || col >= size) {
                        printf("(%d, %d) is off the board.\n", row, col);
                    } else {
                        printf("(%d, %d) is already taken.\n", row, col);
                    }
                    printf("Player %c choice row: ", currentPlayer);
                    row = read_int();
                    printf("Player %c choice column: ", currentPlayer);
                    col = read_int();
                }

                board[row][col] = currentPlayer;
            }

            if(board_has_winner(board,size,currentPlayer)){
                board_print(board,size);
                printf("%c wins!\n",currentPlayer);
                if (currentPlayer == 'X'){
                    xWins+=1;
                }else{
                    oWins+=1;
                }
                roundOver=1;
           } else if (board_is_full(board,size)){
                board_print(board,size);
                printf("It's a draw!\n");
                draws+=1;
                roundOver=1;
           } else{
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
           }
        }
        printf("Score -> X:%d, O: %d, Draws: %d\n",xWins,oWins,draws);
        printf("Play again? (y/n): ");
        redo = read_char();
        while (redo!='y'&& redo!='n'){

            printf("\nPlease enter y or n: ");
            redo = read_char();
        }
        if (redo=='n'){break;}
        printf("1) Two players\n" "2) Play against the computer\n" "Mode: ");
        gameType = read_int();
        while (gameType < 1 || gameType > 2) {
            printf("Please enter a number within the range: ");
            gameType = read_int();
        }

    } while (redo == 'y');
}