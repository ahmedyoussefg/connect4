#ifndef ENDGAME_H
#define ENDGAME_H

#include "endgame.c"

void declareWinner(player p1, player p2, player computer, int mode);
void topPlayers(FILE * winners_file);

#endif