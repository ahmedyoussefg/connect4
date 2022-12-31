#ifndef ENDGAME_H
#define ENDGAME_H

#include "endgame.c"

/// @brief  Function to declare the winner
void declareWinner(player p1, player p2, player computer, int mode, unsigned long long highscores, int played);

/// @brief Function sorts top scores in a file and prints the file on screen
void topPlayers(FILE *winners_file, unsigned long long highscores);

/// @brief check whether the repeated name has been added to the file or not
int check(int array[100], int number); 
#endif