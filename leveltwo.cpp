#include "leveltwo.h" 
#include <iostream>

using namespace std;

Leveltwo::Leveltwo() : Levels("leveltwoback.png", 0, 0)
{
}

Leveltwo::~Leveltwo()
{
	cout<<"Leveltwo deleted"<<endl;
}