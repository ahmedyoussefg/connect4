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

void getParameters(char[] strline, int[] parameters);

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
    int height, width, highscores;
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
        int parameters[3]; // for each parameter (Height, width, highscore in that order)
        while(strline != NULL)
        {
            fscanf(xml_file, "%s%[^\n]%n", strline);
            // for each line
        }

    }        
    printf("%s", strline);
    free(path);
}

void getParameters(char[] strline, int[] parameters)
{
    lowercase(strline);
    // for each parameter
    if (strstr(strline, "height") != NULL)
    {
        scanf("%*s %d%n", &parameters[0]); 
    } 
}