#include "game.h"

void computersMove(int *computer_move, unsigned long long height, unsigned long long width, char board[][width], char symbol)
{
    do
    {
        srand(time(NULL));
        *computer_move = rand() % width + 1; // random number from 1 to 7
    } while (board[0][*computer_move - 1] != ' '); // If the top element in the row is empty then the column is not avaliable

    for (int i = height - 1 ; i >= 0; i--)
    {
        // if the board place (which is the ith in the desired column) is empty, put the piece in the empty place
        if (board[i][*computer_move - 1] == ' ')  
        {
            board[i][*computer_move - 1] = symbol;
            break;
        }
    }
}