#include "levelone.h" 
#include <iostream>

using namespace std;

Levelone::Levelone() : Levels("leveloneback.png", 0, 0)
{
}

Levelone::~Levelone()
{
	cout<<"Levelone deleted"<<endl;
}

/*void Levelone::resetState()
{
	rect.moveTo(0,0);
	appear = true;
}*/
