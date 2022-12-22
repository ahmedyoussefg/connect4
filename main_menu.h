#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "main_menu.c"

/// @brief Function to print options of the main menu
void printMainMenu();

/// @brief Function that takes option in main menu from user and act according to the user's input
/// @param option The user's option
/// @param height The height of the board
/// @param width  The width of the board
/// @param board  The board of the game
/// @param p1     Player One
/// @param p2     Player Two (if the user chose vs Player mode)
/// @param computer Computer (if the user chose vs Computer Mode)
void chooseOption(int option, int height, int width, char board[][width], player p1, player p2, player computer);

#endif