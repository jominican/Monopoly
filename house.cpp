#include "house.h"


using namespace std;

House::House()
{

}

House::~House()
{

}

House::House(string name)
{	
	text = name;
}


void House::buyHouse()//allow buy house, which adds one to the house
{
	houseCount = houseCount + 1;
}

void House::setNumHouse()//set the number of houses
{
	houseCount = 1 ; 
}

int House::getNumHouse()//get the number of houses
{
	return houseCount; 
}

void House::printHouse()
{
	//for (int x=0; x<houseCount; x++){
		cout<<"House "<<houseCount;
	//}
}

string House::printName()
{
	return text; 
}
