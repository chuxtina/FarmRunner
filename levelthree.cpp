#include "levelthree.h" 
#include <iostream>

using namespace std;

Levelthree::Levelthree() : Levels("levelthreeback.png", 0, 0)
{
}

Levelthree::~Levelthree()
{
	cout<<"Levelthree deleted"<<endl;
}