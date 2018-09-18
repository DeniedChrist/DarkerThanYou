	#include"Snake.h"
	#include<iostream>
	#include<conio.h>
	# define xx 120
	# define yy 50
	using namespace std;

	int main()
	{
		Snake s1;
		Snake::c[0] = new int[2];
		Snake::c[0][0] = 0;
		Snake::c[0][1] = 0;
		Snake::c[1] = new int[2];
		Snake::c[1][0] = 0;
		Snake::c[1][1] = 0;
		Snake::c[2] = new int[2];
		Snake::c[2][0] = xx / 2;
		Snake::c[2][1] = yy / 2;
		Boundry b1(xx, yy);
		b1.display();
		Food::genFood(xx / 2, yy / 2);
		s1.ShowConsoleCursor(false);
		
		
		
		while (s1.gameState)
		{
			
			s1.newGen(Snake::Skip);
			
			s1.set();
			Sleep(Snake::speed);
			s1.ShowConsoleCursor(false);
			
			
		}
		cout << "   " << "Your Score :" << Snake::slen - 2 << " " << Snake::speed << endl;
		Sleep(8000);
	}
