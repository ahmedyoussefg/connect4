#ifndef TYPES_H
#define TYPES_H

/// @brief Player data type, has attributes: name (if he is winner), score, id(1 or 2) in case of vsPlayerMode/not in vscomputer mode
///        , symbol (he plays with), highscore(maximum score of the player)
typedef struct {
    char name[100];
    int score;
    int id;
    char symbol;
    int highscore;
} player;

#endif