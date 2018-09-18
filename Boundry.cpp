#include"Boundry.h"
#include<Windows.h>
#include<iostream>
using namespace std;

Boundry::Boundry()
{
	l = 0;
	b = 0;
}
Boundry::Boundry(int len,int br)
{
	l = len;
	b = br;
}
void Boundry::display()
{
	int B = b;
	int L = l;
	int i;
	while (b != 0)
	{
		if ((b == B) || (b == 1))
		{
			for (i = 1; i <= l; i++)
				printf("*");
		}

		else
		{
			for (i = 1; i <= l; i++)
			{
				if ((i == 1) || (i == l))
					printf("*");
				else
					printf(" ");

			}

		}printf("\n");
		b--;
	}
}
bool Boundry::check(int x,int y)
{
	
	if ((x == 119) || (x == 0))
		return true;
	if ((y == 0) || (y == 49))
		return true;
	return false;
}
