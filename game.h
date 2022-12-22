#ifndef GAME_H
#define GAME_H
#include "game.c"

int isFull(int height, int width, char board[][width]); // function to check whether board is full or not, return 1 if full
void dotheMove(int move, int height, int width, char board[][width], char symbol); // each move (move is column)
void playVSHuman(int height, int width, char board[][width], player p1, player p2, player computer); // play
void chooseMode(int game_mode, int height,int width, char board[][width], player p1, player p2, player computer);

#endif