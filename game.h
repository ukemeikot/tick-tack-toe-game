#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <string.h>

/*Global variables declaration*/
char board[3][3];

/*The function prototypes*/
void board_initialize(void);
void playTicTacToe(void);
int check_winner(char sg);
void show_board(int x, int y);

#endif
