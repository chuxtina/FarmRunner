#include <ctime>

#include "treasure.h"
#include <iostream>

using namespace std;

Treasure::Treasure()
{
	image.load("treasure.png");
	hit = false;
	rect = image.rect();
	//rect.translate(x,y);
	resetState();
}

Treasure::~Treasure()
{
	cout<<"Treasure deleted"<<endl;
}

void Treasure::resetState()
{
	srand(time(0));
	int x = rand() % 296 + 40;
	int y = rand() % 396 + 40;
	rect.moveTo(x, y);
}

bool Treasure::isHit()
{
	return hit;
}

void Treasure::setHit(bool h)
{
	hit = h;
}

QRect Treasure::getRect()
{
	return rect;
}

void Treasure::setRect(QRect r)
{
	rect = r;
}

QImage & Treasure::getImage()
{
	return image;
}