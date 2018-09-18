#pragma once
#include"Food.h"
#include<Windows.h>
class Snake:public Food
{
	Food f1;
	
	static bool up;
	static bool down;
	static bool left;
	static bool right;
	static COORD head;
	static COORD tail;
	static int i;
	static int j;
public:
	static bool Skip;
	~Snake();
	static int speed;
	static int slen;
	static bool gameState;
	static int **c;
	void Shit();
	void newg(int);
	void Directions(char);
	void set();
	void Decide(double &, double &, double &, double &, double &);
	void newGen(bool);
	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}

};