/* This is a 2 X 2 Sudoku Game*/
#include "pch.h"
#include<iostream>
using namespace std;
char board[9][9] = {'_','3', '_', '_', '1', '_', '_', '6', '_', 
					'_', '2', '_', '_', '_', '4', '_', '_', '_', 
					'1', '_', '_', '_', '_', '3', '5', '_', '_', 
					'3', '_', '_', '_', '9', '_', '_', '_', '_', 
					'8', '6', '_', '_', '_', '_', '_', '4', '1', 
					'_', '_', '_', '_', '7', '_', '_', '_', '8', 
					'_', '_', '5', '9', '_', '_', '_', '_', '2', 
					'_', '_', '_', '1', '_', '_', '_', '9', '_', 
					'_', '4', '_', '_', '8', '_', '_', '5', '_'};
int n1 = 0, n2 = 0;
char x = ' ';
int flag = 0;
int i = 0, j = 0;
int c = 1, d = 1;
void draw_board()
{
	cout << "00  01  02  03  04  05  06  07  08" << endl;
	cout << "10  11  12  13  14  15  16  17  18"<< endl;
	cout << "20  21  22  23  24  25  26  27  28" << endl;
	cout << "30  31  32  33  34  35  36  37  38" << endl;
	cout << "40  41  42  43  44  45  46  47  38" << endl;
	cout << "50  51  52  53  54  55  56  57  58" << endl;
	cout << "60  61  62  63  64  65  66  67  68" << endl;
	cout << "70  71  72  73  74  75  76  77  78" << endl;
	cout << "80  81  82  83  84  85  86  87  88" << endl;
}
void display_board()
{
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cout << board[i][j] << "   ";
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
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (board[n1][n2] != '_')
				user_input();
		}
	}
	for (i = 0; i < 9; i++)
	{
		if (board[i][n2] == x)
			user_input();
	}
	for (j = 0; j < 9; j++)
	{
		if (board[n1][j] == x)
			user_input();
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (board[n1][n2] == '_')
			{
				board[n1][n2] = x;
			}
			cout << board[i][j] << "   ";
		}
		cout << endl;
	}
}
int game_over()
{
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (board[i][j] != '_' && board[i][j + 1] != '_' && board[i][j + 2] != '_' && board[i][j + 3] && board[i][j+4]!='_' && board[i][j+5]!='_' && board[i][j+6]!='_' && board[i][j+7]!='_' && board[i][j+8]!='_' &&
				board[i + 1][j] != '_' && board[i + 1][j + 1] != '_' && board[i + 1][j + 2] != '_' && board[i + 1][j + 3] && board[i+1][j + 4] != '_' && board[i+1][j + 5] != '_' && board[i+1][j + 6] != '_' && board[i+1][j + 7] != '_' && board[i+1][j + 8] != '_' &&
				board[i + 2][j] != '_' && board[i + 2][j + 1] != '_' && board[i + 2][j + 2] != '_' && board[i + 2][j + 3] && board[i+2][j + 4] != '_' && board[i+2][j + 5] != '_' && board[i+2][j + 6] != '_' && board[i+2][j + 7] != '_' && board[i+2][j + 8] != '_' &&
				board[i + 3][j] != '_' && board[i + 3][j + 1] != '_' && board[i + 3][j + 2] != '_' && board[i + 3][j + 3] != '_'  && board[i+3][j + 4] != '_' && board[i+3][j + 5] != '_' && board[i+3][j + 6] != '_' && board[i+3][j + 7] != '_' && board[i+3][j + 8] != '_' &&
				board[i + 4][j] != '_' && board[i + 4][j + 1] != '_' && board[i + 4][j + 2] != '_' && board[i + 4][j + 3] != '_'  && board[i + 4][j + 4] != '_' && board[i + 4][j + 5] != '_' && board[i + 4][j + 6] != '_' && board[i + 4][j + 7] != '_' && board[i + 4][j + 8] != '_' &&
				board[i + 5][j] != '_' && board[i + 5][j + 1] != '_' && board[i + 5][j + 2] != '_' && board[i + 5][j + 3] != '_'  && board[i + 5][j + 4] != '_' && board[i + 5][j + 5] != '_' && board[i + 5][j + 6] != '_' && board[i + 5][j + 7] != '_' && board[i + 5][j + 8] != '_' &&
				board[i + 6][j] != '_' && board[i + 6][j + 1] != '_' && board[i + 6][j + 2] != '_' && board[i + 6][j + 3] != '_'  && board[i + 6][j + 4] != '_' && board[i + 6][j + 5] != '_' && board[i + 6][j + 6] != '_' && board[i + 6][j + 7] != '_' && board[i + 6][j + 8] != '_' &&
				board[i + 7][j] != '_' && board[i + 7][j + 1] != '_' && board[i + 7][j + 2] != '_' && board[i + 7][j + 3] != '_'  && board[i + 7][j + 4] != '_' && board[i + 7][j + 5] != '_' && board[i + 7][j + 6] != '_' && board[i + 7][j + 7] != '_' && board[i + 7][j + 8] != '_' &&
				board[i + 8][j] != '_' && board[i + 8][j + 1] != '_' && board[i + 8][j + 2] != '_' && board[i + 8][j + 3] != '_'  && board[i + 8][j + 4] != '_' && board[i + 8][j + 5] != '_' && board[i + 8][j + 6] != '_' && board[i + 8][j + 7] != '_' && board[i + 8][j + 8] != '_' )

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