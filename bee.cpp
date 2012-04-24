#include "bee.h" 
#include <iostream>

using namespace std;

Bee::Bee() : Animal("bee.png", 1, 0)
{
}

Bee::~Bee()
{
	cout<<"Bee deleted"<<endl;
}

void Bee::resetState()
{
	rect.moveTo(0,300);
	appear = true;
}

void Bee::automove()
{
	rect.translate(xDir, yDir);
	if(rect.right()>=450)
		setPosition(rand()%386 + 1, rand()%458 + 1);

	if(rect.left()<=0)
		setPosition(rand()%386 + 1, rand()%458 + 1);

	if(rect.top()<=0)
		setPosition(rand()%386 + 1, rand()%458 + 1);

	if(rect.bottom()>=460)
		setPosition(rand()%386 + 1, rand()%458 + 1);
}