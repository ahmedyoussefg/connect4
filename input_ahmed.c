#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[0;33m");
}
void reset_color()
{   
    printf("\033[0m");   
}
void lowercase(char * word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }
}
static int count = 0; // counts number of parameters assigned successfully

void getParameters(char strline[], long parameters[], int k);

void getInt(char strline[], long parameters[], int index);

int main()
{
    char * path = malloc(PATH_MAX);
    int counter = 0;
    do
    {
        printf("Enter the path of configuration file: ");
        if (counter == 0)
        {
            yellow();
            printf("(for default config, type \"default\": ");
            reset_color();
        }
        scanf("%s", path);
        lowercase(path);
        if (strcmp(path, "default") == 0)
        {
            counter = 3;
            break;
        }
        if (fopen(path, "r") == NULL)
        {
            red();
            printf("Please enter the right path (e.g: \"C:\\Connect4\\configuration.xml\")\n");
            reset_color();
            counter++;
        }
        else
        {
            break;
        }
        if (counter == 3)
        {
            break;
        }
    } while (1);
    long height, width, highscores;
    char strline[500];
    if (counter == 3)
    {
        width = 7;
        height = 9;
        highscores = 10;
    }
    else
    {
        FILE * xml_file = fopen(path, "r");
        long parameters[3]; // for each parameter (Height, width, highscore in that order)
        int k = 0;
        while(strline != NULL)
        {
            fscanf(xml_file, "%s", strline);
            // for each line
            getParameters(strline, parameters, k);
            if (count == 3)// all parameters are assigned a value
            {
                break;
            }
        }
        height = parameters[0];
        width = parameters[1];
        highscores = parameters[2];
    }        
    printf("Height: %ld\nWidth: %ld\nHigh Scores: %ld\n", height, width, highscores);
    free(path);
}

void getParameters(char strline[], long parameters[], int k)
{
    lowercase(strline);
    // for each parameter
    if (strstr(strline, "height") != NULL) // if the word "height" appears in the line, then we look for its value
    {
        getInt(strline, parameters, 0); // index of height is zero
    } 
    else if (strstr(strline, "width") != NULL) // if the word "width" appears in the line, then we look for its value
    {
        getInt(strline, parameters, 1); // index of width is one
    }
    else if (strstr(strline, "highscores") != NULL) // if the word "highscores" appears in the line, then we look for its value
    {
        getInt(strline, parameters, 2); // index of highscores is two
    }
    else
    // if the words "height/width/high scores" aren't mentioned in the config we will use the order "Height -> Width -> HighScore"
    {
        getInt(strline, parameters, k);
        k++; // k++
    }  
}
void getInt(char strline[], long parameters[], int index) // function extracts integer from string
{
    char * ptr = strline;
    while(*ptr)
    {
        if (isdigit(*ptr) || (*ptr == '-' || *ptr == '+') && isdigit(*(ptr + 1)))
        {
            parameters[index] = strtol(ptr, &ptr, 10);
            count++;
        }
        else
        {
            ptr++;
        }
    }
    switch (index)
    {
        case 0:
            if (parameters[0] <=3)
            {
                red();
                printf("You entered an invalid height. (MUST be higher than 3)\n");
                yellow();
                printf("We are going to use our default configuration for height...\n");
                reset_color();
                parameters[0] = 7;
            }
            break;
        case 1:
            if (parameters[1] <=3)
            {
                red();
                printf("You entered an invalid width. (MUST be higher than 3)\n");
                yellow();
                printf("We are going to use our default configuration for width...\n");
                reset_color();
                parameters[1] = 9;
            }
            break;
        case 2:
            if (parameters[2] <= 0)
            {
                red();
                printf("You entered an invalid maximum high score. (MUST be higher than zero)\n");
                yellow();
                printf("We are going to use our default configuration for width...\n");
                reset_color();
                parameters[2] = 10;
            }
            break;
        default:
            break;            
    }
}