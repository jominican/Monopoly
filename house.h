#ifndef HOUSE
#define HOUSE
#include <iostream>
#include <sstream>
#include <string>
#include "players.h"
#include "bank.h"

class House 
{
	private:
		int houseCount;
		int flag; 
		string text;
		
	
	public:
		House();
		House(string name);
		//House(int n);
		~House();
		void buyHouse();
		int getNumHouse();
		void setNumHouse();
		string printName();
		void printHouse();


		

};
#endif
