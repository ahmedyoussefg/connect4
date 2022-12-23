#include "types.h"
#include "output.h"
#include "ingamemenu.h"

int isFull(int height, int width, char board[][width]) // function to check whether board is full or not, return 1 if full
{
    int counter = 0;
    for (int j = 0; j < width; j++)
    {
        if (board[0][j] == ' ')         // if any of the top row is empty increase counter
        {
            counter++;
        }
    }
    if (counter == 0)
    {
        return 1; // the game board is full (ended)
    }
    else
    {
        return 0; // the board is not full
    }
}
int isColumnAvaliable(int move, int height, int width, char board[][width]) // move is the column's index
{
    if (move == -1) // in-game menu option
    {
        return 1;
    }
    if (board[0][move] == ' ') // If the top element in the row is empty then the column is avaliable
    {
        return 1;
    }
    else    // the column is not avaliable
    {
        printf("This column is not avaliable!\n");
        return 0;
    }
}

void dotheMove(int move, int height, int width, char board[][width], char symbol, int moves_stack[width * height], int *counter, int *undo, int redos_stack[], int *count_redos)
// move is column's index, counter is for moves_stack
{
    if (move == -1) // The player chose to access in-game menu
    {
        inGameMenu(move, height, width, board, moves_stack, &*counter, &*undo, redos_stack, &*count_redos);
        return;
    }
    for (int i = height - 1 ; i >= 0; i--)
    {
        // if the board place (which is the ith in the desired column) is empty, put the piece in the empty place
        if (board[i][move] == ' ')  
        {
            board[i][move] = symbol;
            break;
        }
    }
}

void playVSHuman(int height, int width, char board[][width], player p1, player p2, player computer) // play
{
    int move; // move of the player each turn

    clock_t timenow=time(NULL);// Time at the start of the game
    int hours,minutes,seconds;//  Time format variables
    
    int moves_stack[width * height]; // Array has all moves "columns" of the game  (of both players)
    int moves_count = 0; // number of moves
    memset(moves_stack, -1, sizeof(moves_stack)); // Initializing the moves stack to negative ones
    
    int full; // variable to check if board is full or not
    int checkeven = 0; // to check if it's player's one turn or player two's turn
    
    char symbol; // symbol played
    int printed_number; // number printed
    
    system("cls"); // clear the commandline interface
    printArray(height,width,board);    // print board (empty)
    
    int undo = 0;  // check if the user made undo
    int redos_stack[width*height]; // all undos are in the redos_stack
    memset(redos_stack, -1, sizeof(redos_stack)); // set all stack to -1
    int count_redos = 0; // counter for redos
    
    while(full == 0)
    {
        if (checkeven % 2 == 0) // even
        {
            // therefore it's player one's turn
            symbol = p1.symbol;
            printed_number = p1.id;
        }
        else
        {
            // therefore it's player two's turn
            symbol = p2.symbol;
            printed_number = p2.id;
        }

        printf("To access in-game menu -> Enter zero\n");        

        do
        {
            printf("Player %d turn...\nEnter Column: ", printed_number);
            scanf("%d", &move);
        
            while(getc(stdin) != '\n');         // remove the buffer
        
        } while(move > width + 1 || move < 0 || (!isColumnAvaliable(move - 1, height, width, board)));

        dotheMove(move - 1, height, width, board, symbol, moves_stack, &moves_count, &undo, redos_stack, &count_redos); // (move - 1) is the chosen column's index
        system("cls"); // clear the command line interface
        if (move != 0)
        {
            moves_stack[moves_count] = move - 1;
            moves_count++;
        }
        if (undo == 1) // if the user made undo:
        {
            redos_stack[count_redos] = moves_stack[moves_count - 1]; // push the last undo - ed move to redos_stack
            count_redos++;                                          // increase redo count by one
            moves_count--;  // decrease move count by one
            moves_stack[moves_count] = -1; // pop last move from the stack 
        }
        else if (undo == 3) // can't redo error (there was no undo)
        {
            checkeven--; // don't increase checkeven
        }
        else if (undo != 2) // if the user didn't make redo nor undo
        {
            count_redos = 0; // set count to zero
            memset(redos_stack, -1, sizeof(redos_stack)); // set all stack to -1
        }
        else if (undo == 2) // if the user made redo
        {
            redos_stack[count_redos - 1] = -1; // the used redos_stack element is set to -1 again
            count_redos--; // decrease count by one
        }
        undo = 0;

        printArray(height,width,board);    // print board

        full = isFull(height, width, board);
        if (full == 1) // if board is full
        {
            break;
        }

        time_t time2 = time(NULL);        // time after the turn
        int time_taken = difftime(time2,timenow); // time different between the start and the end of the loop
        seconds = time_taken % 60;
        minutes = time_taken % 3600 / 60;
        hours = time_taken / 3600;
        printf("Time = %02d : %02d : %02d [HH:MM:SS]\n", hours, minutes, seconds); 

        checkeven++; // increase checkeven by one
    }
}

void chooseMode(int game_mode, int height,int width, char board[][width], player p1, player p2, player computer)
{
    switch (game_mode)
    {
        case 1:
            playVSHuman(height, width, board, p1, p2, computer);
            break;
        case 2:

            break;
        default:
            break;
    }
}