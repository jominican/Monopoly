#ifndef SPACE
#define SPACE
#include <iostream>
#include <sstream>
#include <string>
#include "house.h"

using namespace std;

class Space
{
	private:
		//Action action;
		int nextSpace;
		string name;
		House house; 
		
	
	public://prototyping the methods
		Space(string n);
		~Space();
		string getName();
		void buildHouse(int n);
		int numHouse();

		

};
#endif

