/* This is a 2 X 2 Sudoku Game*/
#include "pch.h"
#include<iostream>
using namespace std;
char board[4][4] = { '_','2','3','_','1','_','_','4','3','_','_','2','_','4','1','_' };
int n1 = 0,n2=0;
char x = ' ';
int flag = 0;
int i = 0, j = 0;
int c = 1;
void draw_board()
{
	cout << "00  01  02  03" << endl;
	cout << "10  11  12  13" << endl;
	cout << "20  21  22  23" << endl;
	cout << "30  31  32  33" << endl;
}
void display_board()
{
	for( i=0; i<4; i++)
	{
		for( j=0; j<4; j++)
		{
			cout << board[i][j]<<"  ";
		}
		cout << endl;
	}
}
void user_input()
{
	cout << "Enter two pairs of numbers that displays the position on the playboard:" << endl;
	cin >> n1 >> n2;
	cout << "Enter the value that u want to place in that position:" << endl;
	cin >> x;
}
void draw()
{
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[n1][n2] != '_')
				user_input();
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (board[i][n2] == x)
			user_input();
	}
	for (j = 0; j < 4; j++)
	{
		if (board[n1][j] == x)
			user_input();
	}
	for ( i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			if (board[n1][n2]=='_')
			{
				board[n1][n2] = x;
			}
			cout << board[i][j]<<"  ";
		}
		cout << endl;
	}
}
int game_over()
{
	for ( i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			if (board[i][j] != '_' && board[i][j + 1] != '_' && board[i][j + 2] != '_' && board[i][j + 3] &&
				board[i + 1][j] != '_' && board[i + 1][j + 1] != '_' && board[i + 1][j + 2] != '_' && board[i + 1][j + 3] &&
				board[i + 2][j] != '_' && board[i + 2][j + 1] != '_' && board[i + 2][j + 2] != '_' && board[i + 2][j + 3] &&
				board[i + 3][j]!='_' && board[i+3][j+1]!='_' && board[i+3][j+2]!='_' && board[i+3][j+3]!='_')

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
		draw();
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
