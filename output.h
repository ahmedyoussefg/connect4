#ifndef OUTPUT_H
#define OUTPUT_H

#include "output.c"


/// @brief Function prints underscore which are borders of the each row in the board 
/// @param width -> The width of the rows (number of entries in row)
void underscore(unsigned long long width);

/// @brief Function prints the board (with borders) and all pieces in board in current state
/// @param height -> The height of the printed board
/// @param width  -> The width of the printed board
/// @param board -> The state of the board to be printed
void printArray(configurations config, char board[][config.width], player p1, player p2);

/// @brief Function resets colour to default color
void reset_color();

/// @brief Function changes text color to red
void red_color();

/// @brief Function changes text color to green
void green_color();

/// @brief Function changes text color to yellow
void yellow_color();

/// @brief Function changes text color to blue
void blue_color();

/// @brief Function changes text color to purple
void purple_color();

/// @brief Function changes text color to cyan
void cyan_color();

/// @brief Function changes text color to bright white
void bright_white_color();

/// @brief Function changes text color to pink
void pink_color();

/// @brief Function changes text color to bright red
void bright_red_color();

/// @brief Function changes text color to bright cyan
void bright_cyan_color();

/// @brief Function changes text color to bright green
void bright_green_color();

/// @brief Function changes text color to bright blue
void bright_blue_color();

/// @brief Function changes text color to dark yellow
void dark_yellow_color();

/// @brief Function changes text color to grey
void grey_color();

/// @brief Function prints a fancy stylish text of Connect Four " the game title "
void print_connect_four();

#endif