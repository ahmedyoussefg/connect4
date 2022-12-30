#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

#include "types.h"
#include "output.h"
#include "main_menu.h"
#include "game.h"
#include "scores.h"
#include "computer_mode.h"
#include "xml_parser.h"

int main()
{
    configurations myconfig;
    myconfig.height = 0;
    myconfig.width = 0;
    myconfig.highscores = 0;
    
    /// @brief counter to count errors for parsing XML before loading default values if we reach counter = 3
    int counter_to_default = 0;

    parseXML(&myconfig, &counter_to_default);       // function parses from XML
    system("cls");
    print_connect_four(); // prints game title

    yellow_color();
    printMainMenu();

    int option; // option in main menu

    do
    {
        printf("Enter option: ");
        scanf("%d", &option); // scan the option
        while(getc(stdin) != '\n');         // remove the buffer
    } while (option <= 0 || option > 4);
    reset_color();

    char board[myconfig.height][myconfig.width];
    memset(board, ' ', sizeof(board)); // initializing all elements of board to whitespace " "
    player p1, p2, computer;
    p1.id = 1;
    p2.id = 2;
    computer.id = 4; // even number
    srand(time(NULL));
    p1.color = rand() % 6 + 1;  // choosing a random color for each player
    do
    {
        p2.color = rand() % 6 + 1;
    } while (p2.color == p1.color);
    do
    {
        computer.color = rand() % 6 + 1;
    } while (computer.color == p1.color);

    p1.symbol = 'X'; //  assumption: player 1 is X
    p2.symbol = 'O'; //              player 2 is O
    computer.symbol = 'O'; // player computer symbol is O
    chooseOption(option, myconfig.height, myconfig.width, board, p1, p2, computer);
    return 0;
}
