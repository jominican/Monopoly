#ifndef BANK
#define BANK
#include <iostream>
#include <sstream>
#include <string>
#include "players.h"

using namespace std;

class Bank
{
	private:
		int bankMoney;
		
	
	public:
		Bank();
		~Bank();
		int setBank(int bank);
		//void payBank(Players &p1, int n );
		void payPlayer(Players &p1, int n );
		

};
#endif

