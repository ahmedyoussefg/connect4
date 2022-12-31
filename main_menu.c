#include "types.h"
#include "game.h"
#include "output.h"

void printMainMenu()
{
    printf("1. Start a new game\n2. Load a game\n3. Top Players\n4. Quit\n");
}
void chooseOption(int option, configurations config, char board[][config.width], player p1, player p2, player computer)
{
    int game_mode;
    switch (option)
    {
        case 1: // start a new game
            do
            {
                yellow_color();
                printf("- Choose game mode:\n1. VS Human\n2. VS Computer\n");
                printf("Enter Option: ");
                reset_color();
                scanf("%d", &game_mode);
                while(getc(stdin) != '\n'); // to remove the buffer
            } while(game_mode <= 0 || game_mode > 2);
            chooseMode(game_mode, config, board, p1, p2, computer);
            break;
        case 2: // load a game
            loadGame();
            break;
        case 3: // top players
            declareWinner(p1, p2, computer, 1, config.highscores, 0); // played = 0
            system("PAUSE");

            break;
        case 4:
            exit(0);
            break;
        default:
            exit(1);
            break;
    }
}