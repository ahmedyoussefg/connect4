int connect4Horizontally(configurations config, char board[][config.width], int move, int *score, char symbol, int row)
{
    int counter1 = 0;
    int counter2 = 0;
    int changes = 0;

    for (int i = 1; i < 4 && move + i <= config.width - 1; i++)
    {
        if (board[row][move + i] == symbol)
        {
            counter1++; // check rightside of the piece
        }
        else
        {
            break;
        }
    }

    for (int i = move - 1; i > move - 4 && i >= 0; i--)
    {
        if (board[row][i] == symbol)
        {
            counter2++; // check leftside of the piece
        }
        else
        {
            break;
        }
    }
    if (counter1 + counter2 >= 3)
    {
        *score  += (counter1 + counter2 - 2);
        changes += (counter1 + counter2 - 2); 
    }
    return changes; // changes in score
}

int connect4Vertically(configurations config, char board[][config.width], int move, int *score, char symbol, int row)
{
    int changes = 0;
    int counter = 0;
    for (int i = row + 1; i != config.height; i++)
    {
        if (board[i][move] == symbol)
        {
            counter++;
        }
    }
    if (counter >= 3)
    {
        *score += 1;
        changes++;
    }
    return changes;
}

int connect4RightDiagonal(configurations config, char board[][config.width], int move, int *score, char symbol, int row)
{
    int counter1 = 0;
    int counter2 = 0;
    int changes = 0;
    int j = 1;
    for (int i = 1; i < 4 && move + i <= config.width - 1 && row - j != -1; i++)
    {
        if (board[row - j][move + i] == symbol)
        {
            counter1++; // check rightside of the piece
        }
        else
        {
            break;
        }
        j++;
    }
    j = 1;
    for (int i = move - 1; i > move - 4 && i >= 0 && row + j != config.height; i--)
    {
        if (board[row + j][i] == symbol)
        {
            counter2++; // check leftside of the piece
        }
        else
        {
            break;
        }
        j++;
    }
    if (counter1 + counter2 >= 3)
    {
        *score  += (counter1 + counter2 - 2);
        changes += (counter1 + counter2 - 2); 
    }
    return changes; // changes in score
}

int connect4LeftDiagonal(configurations config, char board[][config.width], int move, int *score, char symbol, int row)
{
    int counter1 = 0;
    int counter2 = 0;
    int changes = 0;
    int j = 1;
    for (int i = 1; i < 4 && move + i <= config.width - 1 && row + j != config.height; i++)
    {
        if (board[row + j][move + i] == symbol)
        {
            counter1++; // check rightside of the piece
        }
        else
        {
            break;
        }
        j++;
    }

    j = 1;
    
    for (int i = move - 1; i > move - 4 && i >= 0 && row - j != -1; i--)
    {
        if (board[row - j][i] == symbol)
        {
            counter2++; // check leftside of the piece
        }
        else
        {
            break;
        }
        j++;
    }
    if (counter1 + counter2 >= 3)
    {
        *score  += (counter1 + counter2 - 2);
        changes += (counter1 + counter2 - 2); 
    }
    return changes; // changes in score
}

void isConnect4(configurations config, char board[][config.width], int move, int *score, int moves_stack[], int moves_count, char symbol, int to_undo, int mode)
{
    int repeated_moves = 0;
    // To get row's index
    if (mode == 2 && symbol == 'X' && (to_undo == 1 || to_undo == 3))
    {
        for (int i = 0; i < moves_count - 2; i++)
        {
            if (moves_stack[i] == moves_stack[moves_count - 2]) 
            {
                repeated_moves++;
            }
        }    
    }
    else
    {
        for (int i = 0; i < moves_count - 1; i++)
        {
            if (moves_stack[i] == moves_stack[moves_count - 1]) 
            {
                repeated_moves++;
            }
        }
    }
    repeated_moves = config.height - repeated_moves - 1; // row index
    int changes = 0;
    changes += connect4Horizontally(config, board, move, score, symbol, repeated_moves); 
    // checks if the move caused 4 to be connected horizontally
    
    changes += connect4Vertically(config, board, move, score, symbol, repeated_moves); 
    // checks if the move caused 4 to be connected vertically

    changes += connect4RightDiagonal(config, board, move, score, symbol, repeated_moves); 
    // checks if the move caused 4 to be connected in this direction "/"    

    changes += connect4LeftDiagonal(config, board, move, score, symbol, repeated_moves);
    // checks if the move caused 4 to be connected in this direction "\"
    
    if (changes != 0 && to_undo == 1)
    {
        *score = *score - (2 * changes);
    }
}