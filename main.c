#include <stdio.h>
#include "board.h"
#include "input.h"

// William Bailey 1387068
// Wrote the operation checks for the variables: size, gameType (which is essentially the game mode)

/** Myles Leclerc 1391784
 * Wrote the entire main loop of the game (everything past line 37)
 * 
 * the main loop of the game starts with the do-while loop which gets executed before and/or after each round 
 * checking to see at the end if they want to play again or not. It then goes into the while loop where it checks 
 * to see if the person is playing against another person or against the ai. 
 *      Playing against AI: It prints that the ai is moving and calls the ai_move function when it is the AI's turn
 *      Playing against a Person: When it is the persons turn, it asks for the row and column of the players move (making sure the move is valid) 
 *      and executes the move.
 * 
 * It then checks each move to see if the move made by you or the other entity (AI or person) is a winning move, 
 * or a move that results in a draw, and if not, it switches the current player to continue on making moves until 
 * one of those two end conditions met. Once it is met it prints whether it is a win (also says which person won) 
 * or a draw before printing the scores for the amount of wins, losses and draws. It then asks you if you want to play again.
 * 
*/

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

    
    board_print(board, size);
    printf("\n");
}