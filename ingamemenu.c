void undoOrRedo(int move, int height, int width, char board[][width], int moves_stack[width * height], int *counter, int *undo, int undo_redo, int redos_stack[], int *count_redos, int mode)
// function prints the previous(by one) state of the move
{
    int repeated_moves = 0; // variable indicates number of times the column was chosen
    int repeated_moves2 = 0; // variable indicates number of rows the column of the player's move, in computer mode, was chosen
    if (undo_redo == 1) // undo
    {
        for (int i = 0; i < *counter - 1; i++) // to get the row index
        {
            if (moves_stack[i] == moves_stack[*counter - 1])
            {
                repeated_moves++;
            }
        }
        if (mode == 1)
        {
            board[height - repeated_moves - 1][moves_stack[*counter - 1]] = ' '; // empty the last move
            *undo = 1;
        }
        else if (mode == 2)
        {
            for (int i = 0; i < *counter - 2; i++) // to get the row index
            {
                if (moves_stack[i] == moves_stack[*counter - 2]) // the player's move in vs computer mode
                {
                    repeated_moves2++;
                }
            }
            board[height - repeated_moves - 1][moves_stack[*counter - 1]] = ' '; // empty the last move
            board[height - repeated_moves2 - 1][moves_stack[*counter - 2]] = ' '; // empty the previous move before last
            *undo = 1;
        }
    }
    else if (undo_redo == 0) // redo
    {
        if (*count_redos == 0)
        {
            printf("Can't Redo!\n");
            *undo = 3;
            system("PAUSE"); // pause command line interface
            return;
        }
        if (mode == 2)
        {
            for (int i = 0; i < *counter; i++) // to get the row index
            {
                if (moves_stack[i] == redos_stack[*count_redos - 1]) // the player's move
                {
                    repeated_moves++;
                }
            }
            moves_stack[*counter] = redos_stack[*count_redos - 1];
            *counter += 1;
            for (int i = 0; i < *counter; i++) // to get the row index
            {
                if (moves_stack[i] == redos_stack[*count_redos - 2]) // the computer's move
                {
                    repeated_moves2++;
                }
            }
            moves_stack[*counter] = redos_stack[*count_redos - 2];
            *counter += 1;
            *undo = 2; // redo is done
            if (*counter % 2 == 0)
            {
                board[height - repeated_moves - 1][moves_stack[*counter - 2]] = 'X';
                board[height - repeated_moves2 - 1][moves_stack[*counter - 1]] = 'O';
            }
        }
        else
        {
            for (int i = 0; i < *counter; i++) // to get the row index
            {
                if (moves_stack[i] == redos_stack[*count_redos - 1])
                {
                    repeated_moves++;
                }
            }
            *counter = *counter + 1;
            moves_stack[*counter - 1] = redos_stack[*count_redos - 1];
            *undo = 2; // redo is done
            if (*counter % 2 == 0)
            {
                board[height - repeated_moves - 1][moves_stack[*counter - 1]] = 'O';
            }
            else
            {
                board[height - repeated_moves - 1][moves_stack[*counter - 1]] = 'X';
            }
        }
    }
}

void inGameMenu(int move, int height, int width, char board[][width], int moves_stack[width * height], int *counter, int *undo, int redos_stack[], int *count_redos, int mode)
{
    int option2;
    int undo_redo; //  = 1 -> option undo , = 0 -> option redo
    printf("1. Undo\n2. Redo\n3. Save\n4. Quit\n");
    do
    {

        printf("Enter Option: ");
        scanf("%d", &option2);
        while(getc(stdin) != '\n');         // remove the buffer

    } while (option2 > 4 || option2 <= 0);

    switch (option2)
    {
        case 1: // undo
            undoOrRedo(move, height, width, board, moves_stack, counter, undo, 1, redos_stack, count_redos, mode); // undo_redo = 1;
            break;
        case 2: // redo
            undoOrRedo(move, height, width, board, moves_stack, counter, undo, 0, redos_stack, count_redos, mode); // undo_redo = 0;
            break;
        case 3: // save
            break;
        case 4: // exit
            exit(0);
            break;
        default:
            break;
    }
}
