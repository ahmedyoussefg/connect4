void undoOrRedo(int move, int height, int width, char board[][width], int moves_stack[width * height], int counter, int *undo, int undo_redo)
// function prints the previous(by one) state of the move
{
    int repeated_moves = 0; // variable indicates number of times the column was chosen
    char redo_elements[width*height];
    int count_redos = 0;
    for (int i = 0; i < counter; i++) // to get the row index
    {
        if (moves_stack[i] == moves_stack[counter]) 
        {
            repeated_moves++;
        }
    }
    if (undo_redo == 1) // undo
    {
        redo_elements[count_redos] = board[height - repeated_moves - 1][moves_stack[counter]];
        count_redos++;
        board[height - repeated_moves - 1][moves_stack[counter]] = ' '; // empty the last move   
        *undo = 1;
    }
    else // redo
    {
        counter++; // POINTEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEER
        moves_stack[counter] = move;
        board[height - repeated_moves - 1][moves_stack[counter]] = redo_elements[count_redos];
    }
}

void inGameMenu(int move, int height, int width, char board[][width], int moves_stack[width * height], int counter, int *undo)
{
    int option2;
    int undo_redo; //  = 1 -> option undo , = 0 -> option redo
    printf("1. Undo\n2. Redo\n3. Save\n4. Load\n5. Quit\n");
    do
    {
        printf("Enter Option: ");
        scanf("%d", &option2);
    } while (option2 > 5 || option2 < 0);
    
    switch (option2)
    {
        case 1:
            undoOrRedo(move, height, width, board, moves_stack, counter, &*undo, 1); // undo_redo = 1;
            break;
        case 2:

            undoOrRedo(move, height, width, board, moves_stack, counter, &*undo, 0); // undo_redo = 0;
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
    }
}
