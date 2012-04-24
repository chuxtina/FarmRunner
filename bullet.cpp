#include "bullet.h" 
#include <iostream>

using namespace std;

Bullet::Bullet() : Animal("bullet.png", 1, 0)
{
}

Bullet::~Bullet()
{
	cout<<"Bullet deleted"<<endl;
}

void Bullet::resetState()
{
	rect.moveTo(0,0);
	appear = true;
}

void Bullet::automove()
{
	rect.translate(1, 0);

	if (rect.right() >= 390)
		appear = false;

	/*if (rect.left() <= 2)
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
	}*/
}