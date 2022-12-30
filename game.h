#ifndef GAME_H
#define GAME_H
#include "game.c"

/// @brief Function to check if the board of the game is full or not.
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game
/// @return Returns one if the game board is full, returns zero if the game board is not full.
int isFull(configurations config, char board[][config.width]);


/// @brief  Function to check if the column chose by the user is avaliable, if not avaliable,
///         it prints a message indicating so and returns zero
/// @param move   The index of the column chosen by the user
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game 
/// @return Returns one if the column is avaliable, returns zero if the column is not avaliable
int isColumnAvaliable(int move, configurations config, char board[][config.width]);

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
/// @param mode -> Game mode (computer/player)
/// @param p1 -> player one's attributes
/// @param p2 -> player two's attributes
/// @param computer -> computer's attributes
void dotheMove(int move, configurations config, char board[][config.width], char symbol, int moves_stack[], int *counter, int *undo, int redos_stack[], int *count_redos , int mode, player p1, player p2, player computer);

/// @brief        Function that deals with player's moves each turn 
///               and it will be branched to multiple main functions until the game ends
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game
/// @param p1     Player One
/// @param p2     Player Two (if the user chose vs Player mode)
/// @param computer Computer (if the user chose vs Computer mode)
/// @param mode -> Game mode = 1 if vs player ,= 2 if vs computer
/// @param load -> 1 if the user chose load game, 0 otherwise
/// @param moves_count -> 0 if the player didn't load game, and it's initialized with a if he loaded a game.
/// @param moves_stack -> moves stack if player loaded game
void play(configurations config, char board[][config.width], player p1, player p2, player computer, int mode, int load, int moves_count, int moves_stack[]);


/// @brief Function that branches the player to two functions -> playVSHuman or -> playVSComputer
///        according to the user's choice of game mode
/// @param game_mode    Takes the option of the game mode entered by the user 
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game
/// @param p1     Player One
/// @param p2     Player Two (if the user chose vs Player mode)
/// @param computer Computer (if the user chose vs Computer mode)
void chooseMode(int game_mode, configurations config, char board[][config.width], player p1, player p2, player computer);

#endif