#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "types.h"
#include "output.h"
#include "main_menu.h"
#include "game.h"

int main()
{
    printMainMenu();

    int option; // option in main menu

    do
    {
        printf("Enter option: ");
        scanf("%d", &option); // scan the option
        while(getc(stdin) != '\n');         // remove the buffer
    } while (option <= 0 || option > 4);

    int height, width;
    printf("Enter Height and Width: ");
    scanf("%d %d", &height, &width);
    char board[height][width];
    memset(board, ' ', sizeof(board)); // initializing all elements of board to whitespace " "
    player p1, p2, computer;
    p1.id = 1;
    p2.id = 2;
    p1.symbol = 'X'; //  assumption: player 1 is X
    p2.symbol = 'O'; //              player 2 is O
    chooseOption(option, height, width, board, p1, p2, computer);
    return 0;
}
