#pragma once
#include "Boundry.h"
#include<Windows.h>
class Food:public Boundry
{
	int food=3;
	int x;
	int y;
	static COORD c;
public: Food();
		Food(int,int, int);
		void static genFood(int,int);
		void remFood();
		bool match(int,int);
		
};