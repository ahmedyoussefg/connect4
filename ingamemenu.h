#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include "ingamemenu.c"
/// @brief  Function that deals with undo and redo
/// @param move   The index of the column chosen by the user
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game 
/// @param moves_stack The array contains all moves since the start of the game
/// @param counter The number of elements in the moves_stack currently
/// @param undo    checks if the player made undo or not at that move, 1 if undo, 2 if redo
/// @param undo_redo variable to indicate if you the user choose to undo or redo -> it is set 1 if he undos, 0 if he redos
/// @param redos_stack  sends the stack of redos
/// @param count_redos  sends the count of undos in redos 
/// @param mode -> game mode, = 1 if vs player, = 2 if vs computer
void undoOrRedo(int move, configurations config, char board[][config.width], int moves_stack[], int *counter, int *undo, int undo_redo, int redos_stack[], int *count_redos, int mode);

/// @brief  Function prints in-game menu and deals with option of the user
/// @param move   The index of the column chosen by the user
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game 
/// @param moves_stack The array contains all moves since the start of the game
/// @param counter The number of elements in the moves_stack currently
/// @param undo    checks if the player made undo or not at that move, 1 if undo, 2 if redo, 3 at redo error
/// @param redos_stack  sends the stack of redos
/// @param count_redos  sends the count of undos in redos
/// @param mode -> game mode, = 1 if vs player, = 2 if vs computer
/// @param p1 -> player one's attributes
/// @param p2 -> player two's attributes
/// @param computer -> computer's attributes
void inGameMenu(int move, configurations config, char board[][config.width], int moves_stack[], int *counter, int *undo, int redos_stack[], int *count_redos, int mode, player p1, player p2, player computer);

#endif