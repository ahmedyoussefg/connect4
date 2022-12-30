#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "game.h"
#include "types.h"

int check(int array[100], int number) // check whether the repeated name has been added to the file or not
{
    int result = 0;

    for (int i = 0; i < 100; i++)
    {
        if (array[i] == number)
        {
            result = 1;
            break;
        }
    }
    return result;
}

void topPlayers(FILE *winners_file, unsigned long long highscores)
{
    winners_file = fopen("winners.txt", "r");
    char buffer[100];
    char data[100][100];
    char checkData[100][100];
    char tempData[100][1000];
    int arrtemp[100];
    int score[100], i = 0, scoreIndex = 0, j, temp, line, k = 0;
    if (winners_file != NULL)
    {
        while (fgets(buffer, 100, winners_file) != NULL)
        {

            for (int j = 0; j < strlen(buffer); j++)
            {

                if (!(buffer[j] == ':'))
                {
                    data[i][j] = buffer[j];
                }
                else
                {
                    for (j; j < strlen(buffer); j++)
                    {

                        if (isdigit(buffer[j]))
                        {
                            tempData[i][scoreIndex] = buffer[j];
                            score[i] = atoi(tempData[i]); // get the integer value from the new array
                            scoreIndex++;
                        }
                    }
                }
            }
            if (score[i] == 0)
            {
                printf("File is Corrupted ERROR in Line %d\n", i + 1);
                scoreIndex = 0;
                continue;
            }

            scoreIndex = 0;
            i++;
        }

        line = i;
        for (i = 0; i < line; i++)
        {
            for (j = i + 1; j < line; j++)
            {
                if (score[i] < score[j])
                {
                    strcpy(tempData[i], data[j]);
                    strcpy(data[j], data[i]);
                    strcpy(data[i], tempData[i]);
                    temp = score[j];
                    score[j] = score[i];
                    score[i] = temp;
                }
            }
            for (j = 0; j < (strlen(data[i])); j++)
            {
                checkData[i][j] = tolower(data[i][j]); // converting all sorted data to lowercase for later comparison
            }
        }
        temp = 0;
        int firstAp = 0, n = 0;
        FILE *SortedTopper;

        SortedTopper = fopen("sortedToppers.txt", "w");
        SortedTopper = fopen("sortedToppers.txt", "a");

        for (i = 0; i < line; i++) // get the repeated names
        {
            for (j = i + 1; j < line; j++)
            {

                if (!strcmp(checkData[i], checkData[j]))
                {
                    temp = 1;
                    if (check(arrtemp, j))
                    {
                        break;
                    }
                    arrtemp[k] = j;
                    k++;

                    if (firstAp == 1)
                        continue;

                    fprintf(SortedTopper, "%d. %s: %d\n", n + 1, data[i], score[i]);
                    n++;
                    firstAp = 1;
                }
            }
            if (temp == 0 && !check(arrtemp, i))
            {
                fprintf(SortedTopper, "%d. %s: %d\n", n + 1, data[i], score[i]);
                n++;
            }

            temp = 0;
            firstAp = 0;
        }
        fclose(SortedTopper);
        fclose(SortedTopper);
        FILE * ptr1 = fopen("sortedToppers.txt", "r");
        char line[102];
        int counter_to_break = 0;
        while (fgets(line, 100, ptr1) != NULL)
        {
            counter_to_break++;
            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] = '\0';
            }
            printf("%s", line);
            printf("\n");
            if (counter_to_break == highscores)
            {
                break;
            }
        }
        fclose(ptr1);
    }
}

void declareWinner(player p1, player p2, player computer, int mode, unsigned long long highscores)
{
    FILE *winners_file;
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
            fprintf(winners_file, "%s: %d\n", p1.name, p1.score);
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
            fprintf(winners_file, "%s: %d\n", p2.name, p2.score);
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
            if (p1.name[strlen(p1.name) - 1] == '\n')
            {
                p1.name[strlen(p1.name) - 1] = '\0';
            }
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
    topPlayers(&winners_file, highscores);
}
