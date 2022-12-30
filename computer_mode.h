#ifndef COMPUTER_MODE_H
#define COMPUTER_MODE_H

#include "computer_mode.c"


/// @brief Function plays a random move for computer
/// @param computer_move pointer to the move of the computer (column number)
/// @param height Height of the board
/// @param width  Width Of The board
/// @param board  Game-board 2D Array
/// @param symbol 'O'
void computersMove(int *computer_move, unsigned long long height, unsigned long long width, char board[][width], char symbol);

#endif