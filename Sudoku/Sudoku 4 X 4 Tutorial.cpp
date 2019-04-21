#include "pch.h"
#include<iostream>
#include<ctype.h>
#include<string>
#include <fstream>
using namespace std;
ofstream myfile;
ifstream myfileread;
string name;
string readcontent;
char press = ' ';
int i = 0, j = 0;
int pos = 0;
char num = ' ';
int n1 = 0, n2 = 0;
int c;
char board[4][4] = { '_','2','3','_','1','_','_','4','3','_','_','2','_','4','1','_' };
int position[4][4] = { 1,0,0,4,0,6,7,0,0,10,11,0,13,0,0,16 };
struct person {
	string name = " ";
	string date = " ";
	char rate = ' ';
};
person p1;
class Sudoku
{
public:
	void instructions();
	void menu();
	void input_press();
	void check_press();
	void press_function();
	void details();
	void positions();
	void draw_board();
	void input_position();
	void input_number();
	int game_over();
};
void Sudoku::instructions()
{
	cout << "WELCOME TO THE 4 x 4 SUDOKU TUTORIAL." << endl;
	cout << "You will have to enter your details before starting the tutorial." << endl;
	cout << "After the end of the tutorial :" << endl;
	cout << "Press 1 to write a review on this." << endl;
	cout << "Press 2 to read a review about what others have said about this tutorial." << endl;
	cout << "Press 0 to quit the tutorial." << endl;
}
void Sudoku::menu()
{
	cout << "Press 1 to write a review on this tutorial." << endl;
	cout << "Press 2 to read others' review." << endl;
	cout << "Press 0 to quit the tutorial." << endl;
}
void Sudoku::input_press()
{
	cout << "Press a number:" << endl;
	cin >> press;
}
void Sudoku::check_press()
{
	while (1)
	{
		if (press == '1' || press == '2' || press == '0')
			break;
		else
			input_press();
	}
}
void Sudoku::press_function()
{
	if (press == '1')
	{
		cout << "Enter your name, date and rate this tutorial in a scale of 1-5:" << endl;
		cin >> p1.name;
		cin >> p1.date;
		while (p1.rate != '5' && p1.rate != '4' && p1.rate != '3' && p1.rate != '2' && p1.rate != '1')
		{
			cin >> p1.rate;
		}
		myfile.open("review.txt", fstream::app);
		myfile << p1.name;
		myfile << "\t";
		myfile << p1.date;
		myfile << "\t";
		myfile << p1.rate;
		myfile << "\t";
		myfile << "\n";
		myfile.close();
	}
	if (press == '2')
	{
		myfileread.open("review.txt");
		if (myfileread.is_open())
		{
			while (!myfileread.eof())
			{
				myfileread >> readcontent;
				cout << readcontent << endl;
			}
		}
	}
}
void Sudoku::details()
{
	myfile.open("name.txt", fstream::app);
	myfile << "Name\n";
	myfile.close();
	cout << "Enter your name here:" << endl;
	cin >> name;
	myfile.open("name.txt", fstream::app);
	myfile << name;
	myfile << "\n";
	myfile.close();
}
void Sudoku::positions()
{
	cout << "1   2   3   4" << endl;
	cout << "5   6   7   8 " << endl;
	cout << "9   10  11  12 " << endl;
	cout << "13  14  15  16 " << endl;
}
void Sudoku::draw_board()
{
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << board[i][j] << "   ";
		}
		cout << endl;
	}
}
void Sudoku::input_position()
{
	bool go = true;
	while (go || (pos > 16 || pos < 1))
	{
	repeat:cout << "Enter the position where you want to place a number:" << endl;
		cin >> pos;
		if (cin)
		{
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (pos == position[i][j])
					{
						n1 = i;
						n2 = j;
						position[i][j] = 0;
						go = false;
					}

				}
			}
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

}

void Sudoku::input_number()
{
	while (1)
	{
	loop: cout << "Enter a number:" << endl;
		cin >> num;
		if (num == '1' || num == '2' || num == '3' || num == '4')
		{
			for (i = 0; i < 4; i++)
			{
				if (board[i][n2] == num)
					goto loop;
			}
			for (j = 0; j < 4; j++)
			{
				if (board[n1][j] == num)
					goto loop;
			}
			break;
		}
		else
			continue;
	}
	board[n1][n2] = num;
	draw_board();
}

int Sudoku::game_over()
{
	c = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] == '_')
				c = 1;
		}
	}
	return c;
}
int main()
{
	Sudoku su;
	su.instructions();
	su.details();
	while (1)
	{
		su.positions();
		su.draw_board();
	repeat: su.input_position();
		su.input_number();
		su.game_over();
		if (c == 0)
		{
			cout << "Game Over!" << endl;
			break;
		}
		else
			goto repeat;
	}
	cout << endl;
	while (press != '0')
	{
		su.menu();
		su.input_press();
		su.check_press();
		su.press_function();
		if (press == '0')
			break;
	}
	return 0;
}