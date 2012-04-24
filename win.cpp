#include "win.h" 
#include <iostream>

using namespace std;

Win::Win() : Levels("win.png", 0, 0)
{
}

Win::~Win()
{
	cout<<"Win deleted"<<endl;
}