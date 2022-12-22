#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "main_menu.c"

void printMainMenu();
void chooseOption(int option, int height, int width, char board[][width], player p1, player p2, player computer);

#endif