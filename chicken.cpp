#include "chicken.h" 
#include <iostream>

using namespace std;

Chicken::Chicken() : Animal("chicken.png", 1, 0)
{
}

Chicken::~Chicken()
{
	cout<<"Chicken deleted"<<endl;
}

void Chicken::resetState()
{
	rect.moveTo(0,0);
	appear = true;
}

void Chicken::automove()
{
	rect.translate(xDir, yDir);
	if (rect.left() <= 2)
	{
		xDir = 0;
	}
	if (rect.right() >= 388)
	{
		xDir = 0;
	}
	if (rect.top() <= 2)
	{
		yDir = 0;
	}
	if (rect.bottom() >= 458)
	{
		yDir = 0;
	}
}