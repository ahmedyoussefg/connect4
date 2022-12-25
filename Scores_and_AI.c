int connect4Horizontally(int height, int width, char board[][width], int move, int moves_stack[], int moves_count, char symbol, int row)
{
    int counter = 0;
    int counter2 = 0;
    if (move <= width - 1 - 3) // check pieces of the board on the rightside to the new piece
    {
        for (int i = 1; i < 4; i++)
        {
            if (board[row][move + i] == symbol)
            {
                counter++;
            }
        }
    }
    if (move >= 3) // check pieces of the board on the leftside to the new piece
    {
        for (int i = move - 1; i > move - 4; i--)
        {
            if (board[row][i] == symbol)
            {
                counter2++;
            }
        }
    }
    if (counter == 3 || counter2 == 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int connect4Vertically(int height, int width, char board[][width], int move, int moves_stack[], int moves_count, char symbol, int row)
{
    return 0;
}

int connect4RightDiagonal(int height, int width, char board[][width], int move, int moves_stack[], int moves_count, char symbol, int row)
{
return 0;
}

int connect4LeftDiagonal(int height, int width, char board[][width], int move, int moves_stack[], int moves_count, char symbol, int row)
{
 return 0;
}

void isConnect4(int height, int width, char board[][width], int move, int *score, int moves_stack[], int moves_count, char symbol, int to_undo)
{
    int repeated_moves = 0;
    // To get row's index
    for (int i = 0; i < moves_count - 1; i++)
    {
        if (moves_stack[i] == moves_stack[moves_count - 1]) 
        {
            repeated_moves++;
        }
    }
    repeated_moves = height - repeated_moves - 1; // row index
    if (connect4Horizontally(height, width, board, move, moves_stack, moves_count, symbol, repeated_moves) == 1) 
    // checks if the move caused 4 to be connected horizontally
    {
        *score = *score + 1; // increase score by one
        if (to_undo == 1)
        {
            *score = *score - 2;
        }
    }
    if (connect4Vertically(height, width, board, move, moves_stack, moves_count, symbol, repeated_moves) == 1) 
    // checks if the move caused 4 to be connected vertically
    {
        *score = *score + 1;
    }
    if (connect4RightDiagonal(height, width, board, move, moves_stack, moves_count, symbol, repeated_moves) == 1)
    // checks if the move caused 4 to be connected in this direction "/"
    {
        *score = *score + 1;
    }
    if (connect4LeftDiagonal(height, width, board, move, moves_stack, moves_count, symbol, repeated_moves) == 1) 
    // checks if the move caused 4 to be connected in this direction "\"
    {
        *score = *score + 1;
    }
}