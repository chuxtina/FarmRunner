#include "crow.h" 
#include <iostream>

using namespace std;

Crow::Crow() : Animal("crow.PNG", 0, -1)
{
}

Crow::~Crow()
{
	cout<<"Crow deleted"<<endl;
}

void Crow::resetState()
{
	rect.moveTo(390,0);
	appear = true;
}

void Crow::automove()
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