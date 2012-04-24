#include "heart.h" 
#include <iostream>
#include <ctime>

using namespace std;

Heart::Heart() : Animal("heart.png", 1, 0)
{
}

Heart::~Heart()
{
	cout<<"Heart deleted"<<endl;
}

void Heart::resetState()
{
	srand(time(0));
	int x = rand() % 296 + 1;
	int y = rand() % 396 + 1;
	rect.moveTo(x, y);
}
