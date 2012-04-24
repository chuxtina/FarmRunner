#include <ctime>

#include "doghouse.h"
#include <iostream>

using namespace std;

Doghouse::Doghouse()
{
	image.load("doghouse.png");
	hit = false;
	rect = image.rect();
	//rect.translate(x,y);
	resetState();
}

Doghouse::~Doghouse()
{
	cout<<"Doghouse deleted"<<endl;
}

void Doghouse::resetState()
{
	srand(time(0));
	int x = (rand() % 290 + 40)-5;
	int y = rand() % 396 + 1;
	rect.moveTo(x, y);
}

bool Doghouse::isHit()
{
	return hit;
}

void Doghouse::setHit(bool h)
{
	hit = h;
}

QRect Doghouse::getRect()
{
	return rect;
}

void Doghouse::setRect(QRect r)
{
	rect = r;
}

QImage & Doghouse::getImage()
{
	return image;
}