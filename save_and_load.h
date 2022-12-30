#ifndef SAVE_AND_LOAD_H
#define SAVE_AND_LOAD_H

#include "save_and_load.c"



/// @brief Function loads one of the saved games and edits the values of all the parameters:
/// @param config Configurations (width/height/highscores)
/// @param board board state
/// @param p1 p1 attributes
/// @param p2  p2 attributes
/// @param computer  computer attributes
/// @param counter moves counter
/// @param mode mode (vs player = 1), vs computer = 2
void loadGame();

void getSavedData(configurations * saved_config, int * counter, int * mode, player * p1, player * p2, player * computer, int moves_stack[], char board[][saved_config->width]);

/// @brief Function saves the current board state and moves to a binary file
/// @param config Game configuration
/// @param board  board state
/// @param p1  player one's attributes
/// @param p2  player two's attributes
/// @param computer computer's attributes
/// @param counter  moves count 
/// @param mode  game-mode, 1 if vs player, 2 if vs computer
/// @param moves_stack // Array has all moves "columns" of the game  (of both players)
void saveGame(configurations config, char board[][config.width], player p1, player p2, player computer, int *counter, int mode, int moves_stack[]);

#endif