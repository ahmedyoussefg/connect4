#include "types.h"
#include "output.h"
#include "game.h"

void getSavedData(configurations * saved_config, int * counter, int * mode, player * p1, player * p2, player * computer, int moves_stack[], char board[][saved_config->width])
{
    int i = 0;
    char value[100];
    FILE *ptr = fopen("save1.bin", "rb");
    while (fgets(value, 100, ptr) != NULL)
    {
        
    }
}

void loadGame()
{
    yellow_color();
    int option;
    printf("1. Saved Game (1)\n2. Saved Game (2)\n3. Saved Game (3)\n");
    do
    {
        scanf("%d", &option);
        while(getc(stdin) != '\n');         // remove the buffer
    } while (option > 3 || option <= 0);
    reset_color();
    FILE *ptr;
    configurations saved_config;
    int mode, counter = 0;
    srand(time(NULL));
    saved_config.height = 9;
    saved_config.width = 7;
    saved_config.highscores = 10;
    mode = rand() % 2 + 1; // random number from 1 or 2
    player p1, p2, computer;
    p1.score = 0, p2.score = 0, computer.score = 0;
    int moves_stack[saved_config.width * saved_config.height];
    char board[saved_config.height][saved_config.width];
    memset(board, ' ', sizeof(board)); // Initializing the board to spaces

    memset(moves_stack, -1, sizeof(moves_stack)); // Initializing the moves stack to negative ones

    switch (option)
    {
        case 1:
            ptr = fopen("save1.bin", "rb");
            if (ptr == NULL)
            {
                red_color();
                printf("Corrupt save.. Getting Random mode..\n");
                reset_color();
                play(saved_config, board, p1, p2, computer, mode, 0, counter, moves_stack);
            }
            else
            {
                getSavedData(&saved_config, &counter, &mode, &p1, &p2, &computer, moves_stack, board);
            }

            break;
        case 2:
            //ptr = 
            break;
        case 3:
            break;
        default:
            break;
    }
}
void saveGame(configurations config, char board[][config.width], player p1, player p2, player computer, int *counter, int mode, int moves_stack[])
{
    if (fopen("save1.bin", "rb") == NULL) // file save2 not found
    {
        FILE *ptr;
        ptr = fopen("save1.bin", "wb");
        if (mode == 1)
        {
            fprintf(ptr, "%llu\n%llu\n%llu\n%d\n%d\n", config.height, config.width, config.highscores, *counter, mode);
            fprintf(ptr, "%d\n", p1.score);
            fprintf(ptr, "%d\n", p2.score);

            for (int i = 0; i < *counter; i++)
            {
                fprintf(ptr, "%d\n", moves_stack[i]);
            }
        }
        else
        {
            fprintf(ptr, "%llu\n%llu\n%llu\n%d\n%d\n", config.height, config.width, config.highscores, *counter, mode);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", p1.score);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", computer.score);   
            for (int i = 0; i < *counter; i++)
            {
                fprintf(ptr, "%d\n", moves_stack[i]);
            }
        }
    }
    else if (fopen("save2.bin", "rb") == NULL) // file save2 not found
    {
        FILE *ptr;
        ptr = fopen("save2.bin", "wb");
        if (mode == 1)
        {
            fprintf(ptr, "%llu\n%llu\n%llu\n%d\n%d\n", config.height, config.width, config.highscores, *counter, mode);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", p1.score);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", p2.score);
            for (int i = 0; i < *counter; i++)
            {
                fprintf(ptr, "%d\n", moves_stack[i]);
            }
        }
        else
        {
            fprintf(ptr, "%llu\n%llu\n%llu\n%d\n%d\n", config.height, config.width, config.highscores, *counter, mode);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", p1.score);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", computer.score);  
            for (int i = 0; i < *counter; i++)
            {
                fprintf(ptr, "%d\n", moves_stack[i]);
            } 
        }
    }
    else if (fopen("save3.bin", "rb") == NULL)
    {
        FILE *ptr;
        ptr = fopen("save3.bin", "wb");
        if (mode == 1)
        {
            fprintf(ptr, "%llu\n%llu\n%llu\n%d\n%d\n", config.height, config.width, config.highscores, *counter, mode);
            fprintf(ptr, "%d\n%d\n%d\n%d\n", p1.score);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", p2.score);
            for (int i = 0; i < *counter; i++)
            {
                fprintf(ptr, "%d\n", moves_stack[i]);
            }
        }
        else
        {
            fprintf(ptr, "%llu\n%llu\n%llu\n%d\n%d\n", config.height, config.width, config.highscores, *counter, mode);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", p1.score);
            fprintf(ptr, "%d\n%c\n%d\n%d\n", computer.score);   
            for (int i = 0; i < *counter; i++)
            {
                fprintf(ptr, "%d\n", moves_stack[i]);
            }
        }
    }
}