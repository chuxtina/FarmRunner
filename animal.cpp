#include "animal.h"
#include <iostream>

using namespace std;

Animal::Animal(QString file, int xD, int yD)
{
	image.load(file);
	rect = image.rect();
	appear = false;
	xDir = xD;
	yDir = yD;
}

Animal::~Animal()
{
	cout<<"Animal deleted"<<endl;
}
void Animal::setPosition(int xPos, int yPos)
{
	rect.moveTo(xPos, yPos);
}

void Animal::resetState()
{
	rect.moveTo(0,100);
	appear = false;
}

bool Animal::isAppear()
{
	return appear;
}

void Animal::setAppear(bool b)
{
	appear = b;
}
void Animal::moveLeft(int left)
{
	if (rect.left() >= 0)					//Change depending on window size
		rect.moveTo(left, rect.top());
}

void Animal::moveRight(int right)
{
	if (rect.right() <= 388)				//Change depending on window size
		rect.moveTo(right, rect.top());
}

void Animal::moveUp(int up)
{
	if (rect.top() >= 2)					//change depending on window size
		rect.moveTo(rect.left(), up);
}

void Animal::moveDown(int down)
{
	if (rect.bottom() <= 458)				//change depending on window size
		rect.moveTo(rect.left(), down);
}

int Animal::getXD()
{
	return xDir;
}

void Animal::setXD(int x)
{
	xDir = x;
}

int Animal::getYD()
{
	return yDir;
}

void Animal::setYD(int y)
{
	yDir = y;
}

//void Animal::automove(){;}

QRect Animal::getRect()
{
	return rect;
}

QImage & Animal::getImage()
{
	return image;
}