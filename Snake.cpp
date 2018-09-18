	#include"Snake.h"
	#include<iostream>
	#include<conio.h>
	#include<cmath>
	# define xx 120
	# define yy 50
	using namespace std;
	bool Snake::Skip = true;
	int Snake::speed = 200;
	int Snake::slen = 0;
	COORD Snake::head{ xx / 2,yy / 2 };
	COORD Snake::tail{ xx / 2,yy / 2 };
	bool Snake::up = false;
	bool Snake::gameState = true;
	bool Snake::down = true;
	bool Snake::left = false;
	bool Snake::right = false;
	int ** Snake::c = new int*[1000];
	int Snake::i = 3;
	int Snake::j = 0;
	Snake::~Snake()
	{
		for (int i = 0; i < 1000; i++)
			delete c[i];
		delete c;
		c = NULL;
	}
	void Snake::Decide(double &dx, double &dy, double &d1, double &d2, double &x)
	{
		dx = pow((head.X - tail.X), 2);
		dy = pow((head.Y - tail.Y), 2);
		d1 = sqrt(dx + dy);
		d2 = abs(head.Y - tail.Y);
		x = abs(head.X - tail.X);
	}
	
	void Snake::Directions(char ch)
	{
		switch (ch)
		{
		case 'r':	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tail);
			cout << "T"; Shit();  break;
		case 'w':	if ((up == false) && (down == false))
			up = true; left = false; right = false;
			break;
		case 'a':	if ((left == false) && (right == false))
			left = true; up = false; down = false;
			break;
		case 's':	if ((up == false) && (down == false))
			down = true; left = false; right = false;
			break;
		case 'd':	if ((left == false) && (right == false))
			right = true; up = false; down = false;
			break;
		}
	}
	void Snake::set()
	{
		if (_kbhit())
		{
			Directions(_getch());
		}
	}
	void Snake::newg(int x)
	{
		if (x)
		{
			tail.X = c[j][0];
			tail.Y = c[j][1];
			//cout << "tail X : " << tail.X << "\t" << "tail Y : " << tail.Y << endl;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tail);
			cout << " ";
			

			j++;
		}
		c[i] = new int[2];
		c[i][0] = head.X;
		c[i][1] = head.Y;
		//cout << "head X : " << c[i][0] << "\t" << "head Y : " << c[i][1] << endl;
		i++;
	}
	void Snake::Shit()
	{
		
		COORD Skip;
		Skip.X = c[i - 1][0];
		Skip.Y = c[i - 1][1];
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Skip);
		cout << " ";
		j++;

		;
		
	}
	void Snake::newGen(bool x)
	{
		if (x)
		{
			while (slen < 2)
			{

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
				cout << "*";  head.Y++;
				newg(0);
				slen++;
			}
			if (up == true)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
				cout << "*";
				head.Y--; newg(1);
			}
			else if (down == true)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
				cout << "*";
				head.Y++; newg(1);
			}
			else if (left == true)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
				cout << "*";
				head.X--; newg(1);
			}
			else if (right == true)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
				cout << "*";
				head.X++; newg(1);
			}
			if (Food::match(head.X, head.Y))
			{
				speed -= 5;
				slen++;
				if (up == true)
				{
					head.Y--; newg(0);
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
					cout << "*";
				}
				else if (down == true)
				{
					head.Y++; newg(0);
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
					cout << "*";
				}
				else if (left == true)
				{
					head.X--; newg(0);
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
					cout << "*";
				}
				else if (right == true)
				{
					head.X++; newg(0);
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), head);
					cout << "*";
				}
				Food::genFood(xx - 15, yy - 15);
			}
			if (Boundry::check(head.X, head.Y))
			{
				gameState = false;
			}
		}
	}
	
		
	




