
#include "Food.h"
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;
COORD Food::c;
Food::Food()
{
	food = 0;
	x = 0;
	y = 0;
}
Food::Food(int f,int X,int Y)
{
	food = f;
	x = X;
	y = Y;
}
void Food::genFood(int a,int b)
{
	srand(time(0));
	c.X = rand()% a + 1;
	c.Y = rand()% b + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << "@";

}
void Food::remFood()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << ' ';
	food++;
}
bool Food::match(int x ,int y )
{
	if ((c.X == x) && (c.Y == y))
	{
		return true;
	}
	return false;
}
