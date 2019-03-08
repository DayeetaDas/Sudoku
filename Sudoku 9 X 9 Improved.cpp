/* This is a 9 X 9 Sudoku Game*/
#include "pch.h"
#include<iostream>
using namespace std;
int positions[9][9] = { 1,2,3,4,5,6,7,8,9,
						10,11,12,13,14,15,16,17,18,//This array represents the position on the play board
						19,20,21,22,23,24,25,26,27,
						28,29,30,32,32,33,34,35,36,
						37,38,39,40,41,42,43,44,45,
						46,47,48,49,50,51,52,53,54,
						55,56,57,58,59,60,61,62,63,
						64,65,66,67,68,69,70,71,72,
						73,74,75,76,78,79,80,81 };
char board[9][9] = { '_','3', '_', '_', '1', '_', '_', '6', '_',//This array represents the game board
					'_', '2', '_', '_', '_', '4', '_', '_', '_',
					'1', '_', '_', '_', '_', '3', '5', '_', '_',
					'3', '_', '_', '_', '9', '_', '_', '_', '_',
					'8', '6', '_', '_', '_', '_', '_', '4', '1',
					'_', '_', '_', '_', '7', '_', '_', '_', '8',
					'_', '_', '5', '9', '_', '_', '_', '_', '2',
					'_', '_', '_', '1', '_', '_', '_', '9', '_',
					'_', '4', '_', '_', '8', '_', '_', '5', '_' };
int n = 0;
int n1 = 0, n2 = 0;
char x = ' ';
int flag = 0;
int i = 0, j = 0;
int c = 1, d = 1;
void draw_board()//Displays the position on the game board
{
	cout << "1   2   3   4   5   6   7   8   9" << endl;
	cout << "10  11  12  13  14  15  16  17  18" << endl;
	cout << "19  20  21  22  23  24  25  26  27" << endl;
	cout << "28  29  30  31  32  33  34  35  36" << endl;
	cout << "37  38  39  40  41  42  43  44  45" << endl;
	cout << "46  47  48  49  50  51  52  53  54" << endl;
	cout << "55  56  57  58  59  60  61  62  63" << endl;
	cout << "64  65  66  67  68  69  70  71  72" << endl;
	cout << "73  74  75  76  77  78  79  80  81" << endl;
}
void display_board()//Displays the game board
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
void user_input()//Takes the position and the number from the user as input
{
	cout << "Enter a number that displays the position on the playboard:" << endl;
	cin >> n;
	cout << "Enter the value that u want to place in that position:" << endl;
	cin >> x;
}
void check_and_draw()
{
	for (i = 0; i < 9; i++)//checks if the current position is occupied or not
	{
		for (j = 0; j < 9; j++)
		{
			if (positions[i][j] == n && positions[i][j] == 0)
				user_input();
		}
	}
	for (int i = 0; i < 9; i++)//assings the current row and column to n1 and n2 respectively
	{
		for (j = 0; j < 9; j++)
		{
			if (positions[i][j] == n)
			{
				n1 = i;
				n2 = j;
				break;
			}
		}
	}
	for (i = 0; i < 9; i++)//checks if x is already present in the current row
	{
		if (board[i][n2] == x)
			user_input();
	}
	for (j = 0; j < 9; j++)//checks if x is already present in the current column
	{
		if (board[n1][j] == x)
			user_input();
	}
	for (i = 0; i < 9; i++)//assings x to the position n if it is unoccupied
	{
		for (j = 0; j < 9; j++)
		{
			if (positions[i][j] == n && positions[i][j] != 0)
			{
				board[i][j] = x;
				positions[i][j] = 0;
			}
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
}

int game_over()//checks if the game is over or not
{
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (board[i][j] != '_' && board[i][j + 1] != '_' && board[i][j + 2] != '_' && board[i][j + 3] && board[i][j + 4] != '_' && board[i][j + 5] != '_' && board[i][j + 6] != '_' && board[i][j + 7] != '_' && board[i][j + 8] != '_' &&
				board[i + 1][j] != '_' && board[i + 1][j + 1] != '_' && board[i + 1][j + 2] != '_' && board[i + 1][j + 3] && board[i + 1][j + 4] != '_' && board[i + 1][j + 5] != '_' && board[i + 1][j + 6] != '_' && board[i + 1][j + 7] != '_' && board[i + 1][j + 8] != '_' &&
				board[i + 2][j] != '_' && board[i + 2][j + 1] != '_' && board[i + 2][j + 2] != '_' && board[i + 2][j + 3] && board[i + 2][j + 4] != '_' && board[i + 2][j + 5] != '_' && board[i + 2][j + 6] != '_' && board[i + 2][j + 7] != '_' && board[i + 2][j + 8] != '_' &&
				board[i + 3][j] != '_' && board[i + 3][j + 1] != '_' && board[i + 3][j + 2] != '_' && board[i + 3][j + 3] != '_'  && board[i + 3][j + 4] != '_' && board[i + 3][j + 5] != '_' && board[i + 3][j + 6] != '_' && board[i + 3][j + 7] != '_' && board[i + 3][j + 8] != '_' &&
				board[i + 4][j] != '_' && board[i + 4][j + 1] != '_' && board[i + 4][j + 2] != '_' && board[i + 4][j + 3] != '_'  && board[i + 4][j + 4] != '_' && board[i + 4][j + 5] != '_' && board[i + 4][j + 6] != '_' && board[i + 4][j + 7] != '_' && board[i + 4][j + 8] != '_' &&
				board[i + 5][j] != '_' && board[i + 5][j + 1] != '_' && board[i + 5][j + 2] != '_' && board[i + 5][j + 3] != '_'  && board[i + 5][j + 4] != '_' && board[i + 5][j + 5] != '_' && board[i + 5][j + 6] != '_' && board[i + 5][j + 7] != '_' && board[i + 5][j + 8] != '_' &&
				board[i + 6][j] != '_' && board[i + 6][j + 1] != '_' && board[i + 6][j + 2] != '_' && board[i + 6][j + 3] != '_'  && board[i + 6][j + 4] != '_' && board[i + 6][j + 5] != '_' && board[i + 6][j + 6] != '_' && board[i + 6][j + 7] != '_' && board[i + 6][j + 8] != '_' &&
				board[i + 7][j] != '_' && board[i + 7][j + 1] != '_' && board[i + 7][j + 2] != '_' && board[i + 7][j + 3] != '_'  && board[i + 7][j + 4] != '_' && board[i + 7][j + 5] != '_' && board[i + 7][j + 6] != '_' && board[i + 7][j + 7] != '_' && board[i + 7][j + 8] != '_' &&
				board[i + 8][j] != '_' && board[i + 8][j + 1] != '_' && board[i + 8][j + 2] != '_' && board[i + 8][j + 3] != '_'  && board[i + 8][j + 4] != '_' && board[i + 8][j + 5] != '_' && board[i + 8][j + 6] != '_' && board[i + 8][j + 7] != '_' && board[i + 8][j + 8] != '_')

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