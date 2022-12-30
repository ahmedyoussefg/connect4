#include "types.h"
#include "output.h"
#include "ingamemenu.h"
#include "scores.h"
#include "computer_mode.h"
#include "endgame.h"

int isFull(configurations config, char board[][config.width]) // function to check whether board is full or not, return 1 if full
{
    int counter = 0;
    for (int j = 0; j < config.width; j++)
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
int isColumnAvaliable(int move, configurations config, char board[][config.width]) // move is the column's index
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
        red_color();
        printf("This column is not avaliable!\n");
        reset_color();
        return 0;
    }
}

void dotheMove(int move, configurations config, char board[][config.width], char symbol, int moves_stack[], int *counter, int *undo, int redos_stack[], int *count_redos , int mode, player p1, player p2, player computer)
// move is column's index, counter is for moves_stack
{
    if (move == -1) // The player chose to access in-game menu
    {
        inGameMenu(move, config, board, moves_stack, counter, undo, redos_stack, count_redos, mode, p1, p2, computer);
        return;
    }
    for (int i = config.height - 1 ; i >= 0; i--)
    {
        // if the board place (which is the ith in the desired column) is empty, put the piece in the empty place
        if (board[i][move] == ' ')  
        {
            board[i][move] = symbol;
            break;
        }
    }
}

void play(configurations config, char board[][config.width], player p1, player p2, player computer, int mode, int load, int moves_count, int moves_stack[])
// Moves_stack -> Array has all moves "columns" of the game  (of both players) 
{
    int move; // move of the player each turn

    clock_t timenow=time(NULL);// Time at the start of the game
    int hours,minutes,seconds;//  Time format variables
    
    int full; // variable to check if board is full or not
    int checkeven = 0; // to check if it's player's one turn or player two's turn
    
    char symbol; // symbol played
    int printed_number; // number printed
    
    //system("cls"); // clear the commandline interface
    if (mode == 1) //player
    {
        printArray(config, board, p1, p2);    // print board (empty)
        yellow_color();
        printf("Time = 00 : 00 : 00 [HH:MM:SS]\n");
        reset_color();
    }
    else // computer
    {
        printArray(config, board, p1, computer);
        yellow_color();
        printf("Time = 00 : 00 : 00 [HH:MM:SS]\n");
        reset_color();
    }
    int undo = 0;  // check if the user made undo
    int redos_stack[config.width*config.height]; // all undos are in the redos_stack
    memset(redos_stack, -1, sizeof(redos_stack)); // set all stack to -1
    int count_redos = 0; // counter for redos
    p1.score = 0;
    p2.score = 0;
    computer.score = 0;
    int score = 0;
    int computer_move_index;
    while(full == 0)
    {
        if (mode == 1)
        {
            if (checkeven % 2 == 0) // even
            {
                // therefore it's player one's turn
                symbol = p1.symbol;
                score = p1.score;
                printed_number = p1.id;
            }
            else
            {
                // therefore it's player two's turn
                symbol = p2.symbol;
                score = p2.score;
                printed_number = p2.id;
            }
        }
        else if (mode == 2) // vs computer
        {
            if (moves_count % 2 == 0) // player turn
            {
                symbol = p1.symbol;
                score = p1.score;
                printed_number = p1.id;
            }
            else // computer's move
            {
                symbol = computer.symbol;
                score = computer.score;
                printed_number = computer.id;
            }
        }
        if (printed_number != 4) // this is the computer's turn
        {
            do
            {
                green_color();
                printf("To access in-game menu (Undo/Redo/Save/Quit) -> Enter zero\n");  
                reset_color();  
                if (printed_number == 1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);

                }
                printf("Player %d turn...\nEnter Column: ", printed_number);
                scanf("%d", &move);
                reset_color();
                while(getc(stdin) != '\n');         // remove the buffer
            
            } while(move > config.width || move < 0 || (!isColumnAvaliable(move - 1, config, board)));
            dotheMove(move - 1, config, board, symbol, moves_stack, &moves_count, &undo, redos_stack, &count_redos, mode, p1, p2, computer);
            // (move - 1) is the chosen column's index
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), computer.color);
            printf("Computer's turn..\n");
            reset_color();
            computersMove(&computer_move_index, config, board, symbol);
        }
        //system("cls"); // clear the command line interface
        if (move != 0)
        {
            if (printed_number == 4) 
            {
                moves_stack[moves_count] = computer_move_index - 1;
                moves_count++;
            }
            else
            {
                moves_stack[moves_count] = move - 1;
                moves_count++;
            }
        }
        if (undo == 1) // if the user made undo:
        {
            if (mode == 2) // computer mode
            {
                redos_stack[count_redos] = moves_stack[moves_count - 1]; // push the computer's move to redos stack, after undo
                redos_stack[++count_redos] = moves_stack[moves_count - 2]; // push player's move to redos stack after undo
                count_redos++;
                isConnect4(config, board, moves_stack[moves_count - 1], &computer.score, moves_stack, moves_count, 'O', 1, 2);
                isConnect4(config, board, moves_stack[moves_count - 2], &score, moves_stack, moves_count, 'X', 1, 2);
                moves_stack[moves_count - 1] = -1; // pop last 2 move from the stack
                moves_stack[moves_count - 2] = -1; 
                moves_count -= 2; // decrease moves count by 2
            }
            else // player mode
            {
                redos_stack[count_redos] = moves_stack[moves_count - 1]; // push the last undo - ed move to redos_stack
                if (printed_number == 1)
                {
                    isConnect4(config, board, moves_stack[moves_count - 1], &p2.score, moves_stack, moves_count, 'O', 1, 1);
                    // to_undo = 1
                }
                else if (printed_number == 2)
                {
                    isConnect4(config, board, moves_stack[moves_count - 1], &p1.score, moves_stack, moves_count, 'X', 1, 1); // to_undo = 1
                }
                count_redos++;                                          // increase redo count by one
                moves_count--;  // decrease move count by one
                moves_stack[moves_count] = -1; // pop last move from the stack
            }
        }
        else if (undo == 3) // can't redo error (there was no undo)
        {
            if (mode == 1)
            {
                checkeven--; // don't increase checkeven
            }
        }
        else if (undo != 2) // if the user didn't make redo nor undo
        {
            count_redos = 0; // set count to zero
            memset(redos_stack, -1, sizeof(redos_stack)); // set all stack to -1
            if (mode == 1)
            {
                isConnect4(config, board, move - 1, &score, moves_stack, moves_count, symbol, 0, 1); // checks if the move caused
                                                                             // scoring points, then edits the score to higher value
            }
            else if (mode == 2 && printed_number == 1)
            {
                isConnect4(config, board, move - 1, &score, moves_stack, moves_count, symbol, 0, 2); // checks if the move caused
                                                                         // scoring points, then edits the score to higher value
            }
            else if (mode == 2 && printed_number == 4)
            {
                isConnect4(config, board, computer_move_index - 1, &score, moves_stack, moves_count, symbol, 0, 2);
                // checks if the move caused scoring points, then edits the score to higher value
            }
        }
        else if (undo == 2) // if the user made redo
        {
            if (mode == 1) // player vs player
            {
                isConnect4(config, board, redos_stack[count_redos - 1], &score, moves_stack, moves_count, symbol, 0, 1); 
                // checks if the redo-ed move caused points increase
                redos_stack[count_redos - 1] = -1;
                count_redos--; // decrease count by one
            }
            else // computer mode
            {
                isConnect4(config, board, redos_stack[count_redos - 1], &score, moves_stack, moves_count, 'X', 3, 2); 
                // to_undo = 3 to access the player's move
                isConnect4(config, board, redos_stack[count_redos - 2], &computer.score, moves_stack, moves_count, 'O', 0, 2); 
                // checks if the redo-ed move caused points increase
                redos_stack[count_redos - 2] = -1;
                redos_stack[count_redos - 1] = -1; // the used redos_stack element is set to -1 again
                count_redos -=2 ; // decrease count by TWO
            }
        }
        undo = 0;
        if (mode == 1) // player
        {
            printArray(config, board, p1, p2);    // print board
        }
        else // computer
        {
            printArray(config, board, p1, computer);
        }
        full = isFull(config, board);
        if (full == 1) // if board is full
        {
            break;
        }

        time_t time2 = time(NULL);        // time after the turn
        int time_taken = difftime(time2,timenow); // time different between the start and the end of the loop
        seconds = time_taken % 60;
        minutes = time_taken % 3600 / 60;
        hours = time_taken / 3600;

        pink_color();
        printf("Time = %02d : %02d : %02d [HH:MM:SS]\n", hours, minutes, seconds); 
        reset_color();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
        printf("Number Of Moves Of Player One: %d", (moves_count / 2) + (moves_count % 2));
        reset_color();
        if (mode == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
            printf("\tNumber Of Moves Of Player Two: %d\n", moves_count / 2);
            reset_color();
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), computer.color);
            printf("\tNumber Of Moves Of Computer: : %d\n", moves_count / 2);
            reset_color();
        }
        if (printed_number == 1)
        {
            // update player one's score
            p1.score = score;
        }
        else if (printed_number == 2)
        {
            // update player two's score
            p2.score = score;
        }
        else
        {
            computer.score = score;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
        printf("Player %d's score = %d", p1.id, p1.score);
        reset_color();
        if (mode == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
            printf("\t\t\tPlayer %d's score = %d\n", p2.id, p2.score);
        }
        else if (mode == 2)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), computer.color);
            printf("\t\t\tComputer's score = %d\n", computer.score);
        }
        reset_color();
        checkeven++; // increase checkeven by one
    }
    pink_color();
    printf("Time = %02d : %02d : %02d [HH:MM:SS]\n", hours, minutes, seconds); 
    reset_color();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
    printf("Number Of Moves Of Player One: %d", (moves_count / 2) + (moves_count % 2));
    reset_color();
    if (mode == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
        printf("\tNumber Of Moves Of Player Two: %d\n", moves_count / 2);
        reset_color();
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), computer.color);
        printf("\tNumber Of Moves Of Computer: : %d\n", moves_count / 2);
        reset_color();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
    printf("Player %d's score = %d", p1.id, p1.score);
    reset_color();
    if (mode == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
        printf("\t\t\tPlayer %d's score = %d\n", p2.id, p2.score);
    }
    else if (mode == 2)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), computer.color);
        printf("\t\t\tComputer's score = %d\n", computer.score);
    }
    reset_color();
    declareWinner(p1, p2, computer, mode, config.highscores);
}

void chooseMode(int game_mode, configurations config, char board[][config.width], player p1, player p2, player computer)
{
    int moves_stack[config.width * config.height];
    // Moves_stack -> Array has all moves "columns" of the game  (of both players) 
    memset(moves_stack, -1, sizeof(moves_stack)); // Initializing the moves stack to negative ones
    switch (game_mode)
    {
        case 1:
            play(config, board, p1, p2, computer, 1, 0, 0, moves_stack);  // int mode = 1, = vs player mode // load = 0 // moves_count = 0
            break;
        case 2:
            play(config, board, p1, p2, computer, 2, 0, 0, moves_stack); // int mode = 2, = computer mode  // load = 0 // moves_count = 0
            break;
        default:
            break;
    }
}