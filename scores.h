#ifndef SCORES_AND_AI_H
#define SCORES_AND_AI_H
#include "scores.c"

/// @brief Function checks if the play connects 4 horizontally and returns the changes in score "aka: score_after - score_before"
/// @param height height of the board
/// @param width  width of the board
/// @param board  the game- board 2-D array
/// @param move   the column's index
/// @param moves_stack the stack containing all the moves of the game
/// @param score       the score of player
/// @param moves_count count of moves till now
/// @param symbol      symbol of the player
/// @param row         row's index of the play
/// @return returns the changes in score "aka: score_after - score_before"
int connect4Horizontally(int height, int width, char board[][width], int move, int *score, char symbol, int row);


/// @brief Function checks if the play connects 4 vertically and returns the changes in score "aka: score_after - score_before"
/// @param height height of the board
/// @param width  width of the board
/// @param board  the game- board 2-D array
/// @param move   the column's index
/// @param moves_stack the stack containing all the moves of the game
/// @param score       the score of player
/// @param moves_count count of moves till now
/// @param symbol      symbol of the player
/// @param row         row's index of the play
/// @return returns the changes in score "aka: score_after - score_before"
int connect4Vertically(int height, int width, char board[][width], int move, int *score, char symbol, int row);

/// @brief Function checks if the play connects 4 in this "/" direction and returns the changes in score "aka: score_after - score_before"
/// @param height height of the board
/// @param width  width of the board
/// @param board  the game- board 2-D array
/// @param move   the column's index
/// @param moves_stack the stack containing all the moves of the game
/// @param score       the score of player
/// @param moves_count count of moves till now
/// @param symbol      symbol of the player
/// @param row         row's index of the play
/// @return returns the changes in score "aka: score_after - score_before"
int connect4RightDiagonal(int height, int width, char board[][width], int move, int *score, char symbol, int row);

/// @brief Function checks if the play connects 4 in this direction "\\" and returns the changes in score "aka: score_after - score_before"
/// @param height height of the board
/// @param width  width of the board
/// @param board  the game- board 2-D array
/// @param move   the column's index
/// @param moves_stack the stack containing all the moves of the game
/// @param score       the score of player
/// @param moves_count count of moves till now
/// @param symbol      symbol of the player
/// @param row         row's index of the play
/// @return returns the changes in score "aka: score_after - score_before"
int connect4LeftDiagonal(int height, int width, char board[][width], int move, int *score, char symbol, int row);

/// @brief Function checks the change in score and edits the score according to the move in all directions
/// @param height height of the board
/// @param width  width of the board
/// @param board  the game- board 2-D array
/// @param move   the column's index
/// @param moves_stack the stack containing all the moves of the game
/// @param score       the score of player
/// @param moves_count count of moves till now
/// @param symbol      symbol of the player
/// @param to_undo     if the user made undo, becomes = 1 if the user made undo
/// @param mode the game-mode
void isConnect4(int height, int width, char board[][width], int move, int *score, int moves_stack[], int moves_count, char symbol, int to_undo, int mode);

#endif