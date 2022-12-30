#ifndef TYPES_H
#define TYPES_H

/// @brief Player data type, has attributes: name (if he is winner), score, id(1 or 2) in case of vsPlayerMode/not in vscomputer mode
///        , symbol (he plays with), highscore(maximum score of the player), color of the player.
typedef struct {
    char name[256];
    int score;
    int id;
    char symbol;
    int highscore;
    int color;
} player;



/// @brief  configurations of the game-board "Height, Width, Maximum Number of Displayed High Scores"
typedef struct {
    unsigned long long height;
    unsigned long long width;
    unsigned long long highscores;
} configurations;
#endif