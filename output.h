#ifndef OUTPUT_H
#define OUTPUT_H

#include "output.c"


/// @brief Function prints underscore which are borders of the each row in the board 
/// @param width -> The width of the rows (number of entries in row)
void underscore(int width);

/// @brief Function prints the board (with borders) and all pieces in board in current state
/// @param height -> The height of the printed board
/// @param width  -> The width of the printed board
/// @param board -> The state of the board to be printed
void printArray(int height, int width,char board[][width]);

#endif