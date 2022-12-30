#ifndef ENDGAME_H
#define ENDGAME_H

#include "endgame.c"

void declareWinner(player p1, player p2, player computer, int mode, unsigned long long highscores);
void topPlayers(FILE *winners_file, unsigned long long highscores);
int check(int array[100], int number); // check whether the repeated name has been added to the file or not
#endif