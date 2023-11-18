#include "game.h"

/**
  *main - this is the main game function. it is the entry point
  *of the program.
  *Return: 0 on success
  */

int main(void)
{
	char start = ' ';

	printf("--------- Tic Tac Toe ----------\n\n");
	printf("\n* Instructions \n\n");
	printf("\tPlayer 1 sign = X\n");
	printf("\tPlayer 2 sign = O");
	printf("\n\tTo exit from game, Enter -1\n");
	printf("\n\n* Cell Numbers on Board\n");
	board_initialize();

  printf("\n> Press Enter to start...");
 
    scanf("%c", &start);
 
    if (start)
    {
        int userChoice = 1;
        /*restart the game*/
        while (userChoice)
        {
            playTicTacToe();
            printf("\n* Menu\n");
            printf("\nPress 1 to Restart");
            printf("\nPress 0 for Exit");
            printf("\n\nChoice: ");
            scanf("%d", &userChoice);
            if (userChoice)
            {
                board_initialize();
            }
            printf("\n");
        }
    }
    printf("\n :: Thanks for playing Tic Tac Toe game! :: \n");
	return (0);
}

/**
  *board_initialize - initialises the board
  */

void board_initialize(void)
{
	int a, b;
	int count = 1;

	printf("\n\n\t  ");
	for (a = 0; a <= 2; a++)
	{
		for (b = 0; b <= 2; b++)
		{
			board[a][b] = ' ';
		}
	}
	for (a = 0; a <= 2; a++)
	{
		for (b = 0; b <= 2; b++)
		{
			printf("%d", count++);
			if (b < 2)
				printf("  |  ");
		}
		if (a < 2)
			printf("\n\t-----------------\n\t  ");
	}
	printf("\n\n\n");
}

/**
 *show_board - shows the board
 *@x: the x index
 *@y: the y index
 */

void show_board(int x, int y)
{
	int a, b;

	printf("\n\n\t  ");
	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 3; b++)
		{
			printf("%c", board[a][b]);
			if (b < 2)
				printf("  |  ");
		}
		if (a < 2)
			printf("\n\t-----------------\n\t  ");
	}
	printf("\n\n\n");
}
/**
 *update_board - updates the board
 *@cell: the cell number
 *@playersign: the player sign
 *Return: 1 if valid or 0 otherwise
 */
int update_board(int cell, char playersign)
{
	int row = (cell - 1) / 3;
	int column = (cell -1) % 3;
	int isvalid = 1;
	
	/*Accessing individual cell number*/
	if (board[row][column] != ' ')
	{
		printf("\nInvalid: Cell is already filled!\n");
		isvalid = 0;
	}
	else
		board[row][column] = playersign;
	show_board(row, column);
	return (isvalid);
}
/**
 *check_winner - checks for winner
 *@sg: the recieved player sign
 *Return: 1 if winner or 0 otherwise
 */
int check_winner(char sg)
{
/*check all rows*/
	if (board[0][0] == sg && board[0][1] == sg && board[0][2] == sg ||
	board[1][0] == sg && board[1][1] == sg && board[1][2] == sg ||
	board[2][0] == sg && board[2][1] == sg && board[2][2] == sg)
	{
		return 1;
	}
/*check all columns*/
	else if (board[0][0] == sg && board[1][0] == sg && board[2][0] == sg ||
	board[0][1] == sg && board[1][1] == sg && board[2][1] == sg ||
	board[0][2] == sg && board[1][2] == sg && board[2][2] == sg)
	{
		return 1;
	}
/*check both diagonals*/
	else if (board[0][0] == sg && board[1][1] == sg && board[2][2] == sg ||
	board[0][2] == sg && board[1][1] == sg && board[2][0] == sg)
	{
		return 1;
	}
/*There is no winner*/
    return 0;
}
void playTicTacToe()
{
    int gameResult = 0;
    int cell = 0;
    int playCount = 0;
    int updationResult = 1;
 
    char playerSign = ' ';
 
    /*start playing the game*/
    while (!gameResult && playCount < 9)
    {
        if (playCount % 2 == 0)
        {
            /*player 1*/
            printf("\nPlayer 1 [ X ] : ");
            playerSign = 'X';
        }
        else
        {
            /*player 2*/
            printf("\nPlayer 2 [ O ] : ");
            playerSign = 'O';
        }
        scanf("%d", &cell);
        if (cell > 0 && cell < 10)
        {
            updationResult = update_board(cell, playerSign);
            /*if updation is possible*/
            if (updationResult)
            {
                gameResult = check_winner(playerSign);
                /*print the winner of the game*/
                if (gameResult)
                {
                    printf("\t *** Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                }
                playCount++;
            }
        }
        else if (cell == -1)
        {
            printf("\n\tGame Terminated\n");
            return;
        }
        else
        {
            printf("\nPlease Enter a valid cell value\n");
        }
    }
 
    /*no one won the game*/
    if (!gameResult && playCount == 9)
    {
        printf("\n\t *** Draw...  ***\n");
    }
    printf("\n\t --- Game Over --- \n");
}
