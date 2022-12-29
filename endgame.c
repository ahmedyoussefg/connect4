#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "game.h"
#include "types.h"

void topPlayers(FILE * winners_file)
{
    char names[100][256];    // Assumption: maximum high scores list = 100
    int scores[100];
    int line = 0; // each line
    while (winners_file = fopen("winners.txt", "r") != NULL)
    {

    }
}

void declareWinner(player p1, player p2, player computer, int mode)
{    
    FILE * winners_file;
    winners_file = fopen("winners.txt", "a");

    if (mode == 1)
    {
        if (p1.score > p2.score)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);    
            printf("Player one is the winner!\nPlease, Enter Your Name: ");
            fgets(p1.name, 256, stdin);
            reset_color();
            if (p1.name[strlen(p1.name) - 1] == '\n')
            {
                p1.name[strlen(p1.name) - 1] = '\0';
            }
            fprintf(winners_file, "%s %d\n", p1.name, p1.score);
        }
        else if (p2.score > p1.score)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);    
            printf("Player two is the winner!\nPlease, Enter Your Name: ");
            fgets(p2.name, 256, stdin);
            reset_color();
            if (p2.name[strlen(p2.name) - 1] == '\n')
            {
                p2.name[strlen(p2.name) - 1] = '\0';
            }
            fprintf(winners_file, "%s %d\n", p2.name, p2.score);
        }
        else
        {
            yellow_color();
            printf("\t\t\t\t\tDraw !\n");
            reset_color();
        }
    }
    else
    {
        if (p1.score > computer.score)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);    
            printf("Player one is the winner!\nPlease, Enter Your Name: ");
            fgets(p1.name, 256, stdin);
            fprintf(winners_file, "%s: %d\n", p1.name, p1.score);
            reset_color();
        }
        else if (p1.score == computer.score)
        {
            yellow_color();
            printf("\t\t\t\t\tDraw !\n");
            reset_color();
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), computer.color);    
            printf("Computer is the winner!\n");
            reset_color();
        }
    }
    fclose(winners_file);
    topPlayers(&winners_file);
}