#include "game.h"

void computersMove(int *computer_move, configurations config, char board[][config.width], char symbol)
{
    do
    {
        srand(time(NULL));
        *computer_move = rand() % config.width + 1; // random number from 1 to 7
    } while (board[0][*computer_move - 1] != ' '); // If the top element in the row is empty then the column is not avaliable

    for (int i = config.height - 1 ; i >= 0; i--)
    {
        // if the board place (which is the ith in the desired column) is empty, put the piece in the empty place
        if (board[i][*computer_move - 1] == ' ')  
        {
            board[i][*computer_move - 1] = symbol;
            break;
        }
    }
}