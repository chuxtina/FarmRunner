#include "pig.h" 
#include <iostream>

using namespace std;

Pig::Pig() : Animal("pig.png", 1, 0)
{
}

Pig::~Pig()
{
	cout<<"Pig deleted"<<endl;
}

void Pig::resetState()
{
	rect.moveTo(0,100);
	appear = false;
}

void Pig::automove()
{
	rect.translate(xDir, yDir);
	if(rect.right()>=450)
		resetState();

	if(rect.left()<=0)
		resetState();

	if(rect.top()<=0)
		resetState();

	if(rect.bottom()>=460)
		resetState();
}