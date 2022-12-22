#include "types.h"

void underscore(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("----"); 
    }
    printf("-\n");

}

void printArray(int height, int width, char board[][width])
{
    for (int i = 1; i < width + 1; i++)
    {
        printf("  %d ", i);
    }
    printf("\n");
    underscore(width);
    for (int i = 0; i < height; i++) // for each row
    {
        printf("│");
        for (int j = 0; j < width; j++) // for each column
        {
            printf(" %c ", board[i][j]);
            printf("│");
        }
        printf("\n");
        underscore(width);
    }
}
