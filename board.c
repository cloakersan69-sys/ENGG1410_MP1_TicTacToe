#include "board.h"
#include <stdio.h>

// William Bailey 1387068.
// Wrote the functions for board_print, board_has_winner, and board_is_full. As well as fixed any bugs 
//found within the code.

/** Myles Leclerc 1391784
 * Wrote the board_init, move_is_valid, and ai_move functions. Also wrote the function headers for each function. 
 * Fixed bugs found in code.
*/

/**
 * What it does: Initializes/Resets the Board by writing EMPTY to every cell. 
 * It is used at the beginning of every round before even the first move is played.
 * 
 * Parameters:
 * 
 * - board is the n x n grid to reset that was previously being played on.
 * - n is the size of the board that is being played 
 * 
 * Returns:
 * 
 * - void because it modifies the board in place.
 */

void board_init(char board[MAX_SIZE][MAX_SIZE], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j]=EMPTY;
        }
        
    }
    
}

/**
 * What it does: it prints the current board to the screen along with row and column numbers (0 to n-1) along the edges, 
 * so a player can see the coordinates for their next move.
 * 
 * Parameters:
 * 
 * - board is the n x n grid to print (with formating)
 * - n is the size of the board that is being played 
 * 
 * Returns:
 * 
 * - void because it only prints ASCII characters to the terminal
 */

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
/**
 * What it does: Checks if the row and column of a move is valid within the chosen size of the board
 * 
 * Parameters:
 * 
 * - board is the board that is currently being played on
 * - n is the size of the active board
 * - row is the integer corresponding to the row that is being checked in the board which is a grid. 
 * - col is the integer corresponding to the column that is being checked in the board which is a grid. 
 * 
 * Returns:
 * 
 * - condition (1 or 0); 0 says that the move is not valid while 1 says that its possible*/ 
int move_is_valid(char board[MAX_SIZE][MAX_SIZE], int n, int row, int col){
    if (row < 0 || row >= n || col < 0 || col >= n) {
        return 0;
    }
    return board[row][col] == EMPTY;
}
/**
 * What it does: Checks whether the given mark has won by filling an entire row, 
 * an entire column, or either a diagonal of the board.
 * Parameters:
 * - board is the board currently being played on
 * - n is the size of the board that is being used to play tic-tac-toe
 * - mark is the character to look for to check if they won (either 'X' or 'O')
 * Returns:
 *  - an integer (either 1 or 0). 1 means that the board does have a winner.
 */
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

/**
 * What it does: Checks if the board is full with characters.
 * Parameters:
 * - board is the board currently being played on
 * - n is the size of the board that is being used to play the game
 * Returns:
 * - an integer. it returns 1 if the board isn't full and 0 if it is full.
 */
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


/**
 * What it does: it makes a computer move against the human player. It does this by first checking if the AI can win 
 * by going through all possible cells (of the grid) that aren't empty and checking if it is possible for the AI to 
 * get an immediate win. If it can't, it then checks to see if the Human player can win one move into the future
 * so that the AI can block that move. If it cant get an immediate win or if there's no immediate future move to block 
 * (from the human opponent) it then just picks the first empty cell it see's to make a move on.
 * Parameters:
 * - board is the board that is currently being played on
 * - n is the size of the board currently being played on
 * - ai_mark is the character mark of the computer/AI which would either be 'X' or 'O'
 * - human_mark is the character mark of the human opponent which would either be 'X' or 'O'
 * Returns:
 * - void because the function only edits the board.
 */
void ai_move(char board[MAX_SIZE][MAX_SIZE], int n, char ai_mark, char human_mark){
    //Take a win if ones available
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c]==EMPTY){
                board[r][c] = ai_mark;
                if (board_has_winner(board,n,ai_mark)){return;}
                board[r][c] = EMPTY;// it resets the cell to empty so that every time in goes through a cell 
                //it only moves if that move makes it a win, hence the if statement
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
                board[r][c]=EMPTY;// it resets the cell to empty so that every time in goes through a cell 
                //it checks to see if the human can win by making that move so that the ai can block it, 
                //hence the if statement and the code inside it
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