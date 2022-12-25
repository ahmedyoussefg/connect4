#ifndef SCORES_AND_AI_H
#define SCORES_AND_AI_H
#include "Scores_and_AI.c"

int connect4Horizontally(int height, int width, char board[][width], int move, int moves_stack[], int moves_count, char symbol, int row);

int connect4Vertically(int height, int width, char board[][width], int move, int moves_stack[], int moves_count, char symbol, int row);

int connect4RightDiagonal(int height, int width, char board[][width], int move, int moves_stack[], int moves_count, char symbol, int row);
int connect4LeftDiagonal(int height, int width, char board[][width], int move, int moves_stack[], int moves_count, char symbol, int row);
void isConnect4(int height, int width, char board[][width], int move, int *score, int moves_stack[], int moves_count, char symbol, int to_undo);

#endif