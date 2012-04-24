#include "lose.h" 
#include <iostream>

using namespace std;

Lose::Lose() : Levels("lose.png", 0, 0)
{
}

Lose::~Lose()
{
	cout<<"Lose deleted"<<endl;
}