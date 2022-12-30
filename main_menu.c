#include "types.h"
#include "game.h"
#include "output.h"

void printMainMenu()
{
    printf("1. Start a new game\n2. Load a game\n3. Top Players\n4. Quit\n");
}
void chooseOption(int option, unsigned long long height, unsigned long long width, char board[][width], player p1, player p2, player computer)
{
    int game_mode;
    switch (option)
    {
        case 1:
            do
            {
                yellow_color();
                printf("- Choose game mode:\n1. VS Human\n2. VS Computer\n");
                printf("Enter Option: ");
                reset_color();
                scanf("%d", &game_mode);
                while(getc(stdin) != '\n'); // to remove the buffer
            } while(game_mode <= 0 || game_mode > 2);
            chooseMode(game_mode, height, width, board, p1, p2, computer);
            break;
        case 2:

            break;
        case 3:
            break;
        case 4:

            break;
        default:
            exit(0);
            break;
    }
}