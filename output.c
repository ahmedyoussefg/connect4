#include "types.h"

void reset_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void red_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

void green_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
}

void yellow_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}

void blue_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}

void purple_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
}

void cyan_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
}

void bright_white_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void pink_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
}
void bright_red_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}

void bright_cyan_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

void bright_green_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}

void bright_blue_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
}

void dark_yellow_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
}

void grey_color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}

void print_connect_four()
{
    blue_color();
    printf("\t\t  C O N N E C T");

    red_color();
    printf("   F O U R\n\n");
    reset_color();
}

void underscore(unsigned long long width)
{
    for (unsigned long long i = 0; i < width; i++)
    {
        printf("----");
    }
    printf("-\n");
}

void printArray(configurations config, char board[][config.width], player p1, player p2)
{
    print_connect_four(); // game title
    printf("\n\t\t");
    yellow_color();
    for (int i = 1; i < config.width + 1; i++)
    {
        printf("  %d ", i);
    }
    printf("\n");
    printf("\t\t");
    underscore(config.width);
    reset_color();
    SetConsoleOutputCP(CP_UTF8); // for the ??? symbol
    for (unsigned long long i = 0; i < config.height; i++) // for each row
    {
        printf("\t\t");
        yellow_color();
        printf("???");
        reset_color();
        for (unsigned long long j = 0; j < config.width; j++) // for each column
        {
            if (board[i][j] == 'X')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
                printf(" ??? ");
                reset_color();
            }
            else if (board[i][j] == 'O')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
                printf(" ??? ");
                reset_color();
            }
            else
            {
                printf("   ");
            }
            yellow_color();
            printf("???");
            reset_color();
        }
        printf("\n");
        printf("\t\t");
        yellow_color();
        underscore(config.width);
        reset_color();
    }
}
