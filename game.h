#include <stdio.h>
#include "output.h"

typedef struct  {
    char name[100];
    int score;
    int id;
    char symbol;
    int highscore;
} player;

int isFull(int height, int width, char board[][width]) // function to check whether board is full or not, return 1 if full
{
    int counter = 0;
    for (int j = 0; j < width; j++)
    {
        if (board[0][j] == " ")
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

void dotheMove(int move, int height, int width, char board[][width], char symbol) // each move (move is column)
{
    for (int i = height - 1 ; i >= 0; i--)
    {
        // if the board place (which is the ith in the desired column) is empty, put the piece in the empty place
        if (board[i][move] == " ")  
        {
            board[i][move] = symbol;
        }
    }
}

void playVSHuman(int height, int width, char board[][width], player p1, player p2, player computer) // play
{
    int move;
    int full; // variable to check if board is full or not
    int checkeven = 0;
    char symbol; // symbol played
    int printed_number; // number printed
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
        printArray(height,width,board);    // print board
        do
        {
            printf("Enter Column..\nPlayer %d turn...\n", printed_number);
            scanf("%d", &move);
        } while(move > width + 1 || move < 1); 
        dotheMove(move - 1, height, width, board, symbol); // (move - 1) is the chosen column's index
        full = isFull(height, width, board);
        if (full = 1) // if board is full
        {
            break;
        }
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