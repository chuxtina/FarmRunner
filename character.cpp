#include "character.h"
#include <iostream>

using namespace std;

Character::Character()
{
	image.load("jack.png");
	rect = image.rect();
	xD = 0;
	yD = 0;
	resetState();
}

Character::~Character()
{
	cout<<"Character deleted"<<endl;
}

void Character::resetState()
{
	rect.moveTo(210,40);
}

void Character::moveLeft(int left)
{
	if (rect.left() >= 2)					//Change depending on window size
		rect.moveTo(left, rect.top());
}

void Character::moveRight(int right)
{
	if (rect.right() <= 388)				//Change depending on window size
		rect.moveTo(right, rect.top());
}

void Character::moveUp(int up)
{
	if (rect.top() >= 2)					//change depending on window size
		rect.moveTo(rect.left(), up);
}

void Character::moveDown(int down)
{
	if (rect.bottom() <= 458)				//change depending on window size
		rect.moveTo(rect.left(), down);
}

int Character::getXD()
{
	return xD;
}

void Character::setXD(int x)
{
	xD = x;
}

int Character::getYD()
{
	return yD;
}

void Character::setYD(int y)
{
	yD = y;
}

void Character::automove()
{
	rect.translate(xD, yD);

	if (rect.left() <= 0)
	{
		xD = 0;
	}
	if (rect.right() >= 390)
	{
		xD = 0;
	}
	if (rect.top() <= 0)
	{
		yD = 0;
	}
	if (rect.bottom() >= 460)
	{
		yD = 0;
	}
}

QRect Character::getRect()
{
	return rect;
}

QImage & Character::getImage()
{
	return image;
}