#include "start.h" 
#include <iostream>

using namespace std;

Start::Start() : Levels("FarmRunner2.png", 0, 0)
{
}

Start::~Start()
{
	cout<<"Start deleted"<<endl;
}