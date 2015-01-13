#include "space.h"




Space::Space(string n)//give a name to the space
{
	name = n;
}

Space::~Space()
{

}

string Space::getName()//get the name of the space
{

	return name;
}

void Space::buildHouse(int n)
{
	house.buyHouse();
	//return n+1;
}

int Space::numHouse()//print the number of houses
{
	return house.getNumHouse();
}

