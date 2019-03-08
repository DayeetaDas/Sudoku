/* This is a 4 X 4 Sudoku Game*/
#include "pch.h"
#include<iostream>
using namespace std;
int positions[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };//This array contains the positions of the boxes in the sudoku block
char board[4][4] = { '_','2','3','_','1','_','_','4','3','_','_','2','_','4','1','_' };//This array represents the sudoku board
int n = 0;//contains the position in the board as input from the user
int n1 = 0, n2 = 0;//contains the current row and column position
char x = ' ';//contains the number given as input by the user to be placed in position n
int i = 0, j = 0;//represents the counter variables
int c = 1;//acts as a flag for the Game_Over() function
void draw_board()//This function displays the positions on the playboard
{
	cout << "1   2   3   4" << endl;
	cout << "5   6   7   8" << endl;
	cout << "9   10  11  12" << endl;
	cout << "13  14  15  16" << endl;
}
void display_board()//This function draws the board
{
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
}
void user_input()//Takes the position and the number from the user as input
{
	cout << "Enter a number that displays the position on the playboard:" << endl;
	cin >> n;
	cout << "Enter the value that u want to place in that position:" << endl;
	cin >> x;
}
void check_and_draw()
{
	for (i = 0; i < 4; i++)//checks if the current position is occupied or not
	{
		for (j = 0; j < 4; j++)
		{
			if (positions[i][j]==n && positions[i][j]==0)
				user_input();
		}
	}
	for (int i = 0; i < 4; i++)//assings the current row and column to n1 and n2 respectively
	{
		for (j = 0; j < 4; j++)
		{
			if (positions[i][j] == n)
			{
				n1 = i;
				n2 = j;
				break;
			}
		}
	}
	for (i = 0; i < 4; i++)//checks if x is already present in the current row
	{
		if (board[i][n2] == x)
			user_input();
	}
	for (j = 0; j < 4; j++)//checks if x is already present in the current column
	{
		if (board[n1][j] == x)
			user_input();
	}
	for (i = 0; i < 4; i++)//assings x to the position n if it is unoccupied
	{
		for (j = 0; j < 4; j++)
		{
			if (positions[i][j] == n && positions[i][j]!= 0)
			{
				board[i][j] = x;
				positions[i][j] = 0;
			}
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
}

int game_over()//checks if the Game is over or not
{
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] != '_' && board[i][j + 1] != '_' && board[i][j + 2] != '_' && board[i][j + 3] &&
				board[i + 1][j] != '_' && board[i + 1][j + 1] != '_' && board[i + 1][j + 2] != '_' && board[i + 1][j + 3] &&
				board[i + 2][j] != '_' && board[i + 2][j + 1] != '_' && board[i + 2][j + 2] != '_' && board[i + 2][j + 3] &&
				board[i + 3][j] != '_' && board[i + 3][j + 1] != '_' && board[i + 3][j + 2] != '_' && board[i + 3][j + 3] != '_')

				c = 0;
			break;
		}
		break;
	}
	return c;
}
int main()
{
	draw_board();
	cout << endl;
	display_board();
	cout << endl;
	while (1)
	{
		draw_board();
		cout << endl;
		user_input();
		cout << endl;
		check_and_draw();
		cout << endl;
		game_over();
		if (c == 0)
		{
			cout << "Game Over!" << endl;
			break;
		}
	}
	return 0;
}