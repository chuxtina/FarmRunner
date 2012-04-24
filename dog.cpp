#include "dog.h" 
#include <iostream>

using namespace std;

Dog::Dog() : Animal("dog.png", 0, 1)
{
}

Dog::~Dog()
{
	cout<<"Dog deleted"<<endl;
}

void Dog::resetState()
{
	rect.moveTo(195,0);
	appear = false;
}

void Dog::automove()
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