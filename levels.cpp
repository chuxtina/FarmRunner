#include "levels.h"
#include <iostream>

using namespace std;

Levels::Levels(QString file, int xD, int yD)
{
	image.load(file);
	rect = image.rect();
	appear = false;
	xDir = xD;
	yDir = yD;
}

Levels::~Levels()
{
	cout<<"Levels deleted"<<endl;
}
void Levels::setPosition(int xPos, int yPos)
{
	rect.moveTo(xPos, yPos);
}

void Levels::resetState()
{
	rect.moveTo(0,0);
	appear = false;
}

bool Levels::isAppear()
{
	return appear;
}

void Levels::setAppear(bool b)
{
	appear = b;
}


int Levels::getXD()
{
	return xDir;
}

void Levels::setXD(int x)
{
	xDir = x;
}

int Levels::getYD()
{
	return yDir;
}

void Levels::setYD(int y)
{
	yDir = y;
}

QRect Levels::getRect()
{
	return rect;
}

QImage & Levels::getImage()
{
	return image;
}