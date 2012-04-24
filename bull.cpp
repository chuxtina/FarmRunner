#include "bull.h" 
#include <iostream>

using namespace std;

Bull::Bull() : Animal("bull.png", -1, 0)
{
}

Bull::~Bull()
{
	cout<<"Bull deleted"<<endl;
}

void Bull::resetState()
{
	rect.moveTo(390,300);
	appear = false;
}

void Bull::automove()
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