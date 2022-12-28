#ifndef GAME_H
#define GAME_H
#include "game.c"

/// @brief Function to check if the board of the game is full or not.
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game
/// @return Returns one if the game board is full, returns zero if the game board is not full.
int isFull(int height, int width, char board[][width]);


/// @brief  Function to check if the column chose by the user is avaliable, if not avaliable,
///         it prints a message indicating so and returns zero
/// @param move   The index of the column chosen by the user
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game 
/// @return Returns one if the column is avaliable, returns zero if the column is not avaliable
int isColumnAvaliable(int move, int height, int width, char board[][width]);

/// @brief        Function edits the board to the state of the board after the user puts the piece in the avaliable place
/// @param move   The index of the column chosen by the user
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game 
/// @param symbol Player's symbol to be added inside the board's column
/// @param moves_stack[] sends the stack of all moves played till now
/// @param counter sends the moves count up untill that move
/// @param undo    checks if the player made undo or not at that move, 1 if undo, 2 if redo, 3 at redo error
/// @param redos_stack  sends the stack of redos
/// @param count_redos  sends the count of undos in redos 
void dotheMove(int move, int height, int width, char board[][width], char symbol, int moves_stack[width * height], int *counter, int *undo, int redos_stack[], int *count_redos, int mode);

/// @brief        Function that deals with player's moves each turn 
///               and it will be branched to multiple main functions until the game ends
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game
/// @param p1     Player One
/// @param p2     Player Two (if the user chose vs Player mode)
/// @param computer Computer (if the user chose vs Computer mode)
void playVSHuman(int height, int width, char board[][width], player p1, player p2, player computer, int mode);


/// @brief Function that branches the player to two functions -> playVSHuman or -> playVSComputer
///        according to the user's choice of game mode
/// @param game_mode    Takes the option of the game mode entered by the user 
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game
/// @param p1     Player One
/// @param p2     Player Two (if the user chose vs Player mode)
/// @param computer Computer (if the user chose vs Computer mode)
void chooseMode(int game_mode, int height,int width, char board[][width], player p1, player p2, player computer);

#endif