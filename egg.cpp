#include "egg.h" 
#include <iostream>

using namespace std;

Egg::Egg() : Animal("egg.png", 1, 0)
{
}

Egg::~Egg()
{
	cout<<"Egg deleted"<<endl;
}

void Egg::resetState()
{
	rect.moveTo(0,0);
	appear = true;
}

void Egg::automove()
{
	rect.translate(0, 1);

	/*if (rect.right() >= 390)
		appear = false;

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
	}*/
	if (rect.bottom() >= 458)
	{
		appear = false;
	}
}