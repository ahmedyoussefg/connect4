#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include "ingamemenu.c"
/// @brief  Function that deals with undo
/// @param move   The index of the column chosen by the user
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game 
/// @param moves_stack The array contains all moves since the start of the game
/// @param counter The number of elements in the moves_stack currently
/// @param undo // Variable checks whether the user made undo or no
///
void undoOrRedo(int move, int height, int width, char board[][width], int moves_stack[width * height], int counter, int *undo, int undo_redo);

/// @brief  Function prints in-game menu and deals with option of the user
/// @param move   The index of the column chosen by the user
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game 
/// @param moves_stack The array contains all moves since the start of the game
/// @param counter The number of elements in the moves_stack currently
/// @param undo // Variable checks whether the user made undo or no
void inGameMenu(int move, int height, int width, char board[][width], int moves_stack[width * height], int counter, int *undo);

#endif