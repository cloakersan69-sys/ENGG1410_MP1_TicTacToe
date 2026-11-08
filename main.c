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
                
            } else{

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
            prinf("\nPlease enter y or n: ");
            redo = read_char();
        }

    } while (redo == 'y');
    

    board_print(board, size);
    printf("\n");
}