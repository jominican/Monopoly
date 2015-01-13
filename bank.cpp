#include "bank.h"

using namespace std;

Bank::Bank()
{

}

Bank::~Bank()
{

}

int Bank::setBank(int bank)//set the bank money
{
	bankMoney = bank;
	return bankMoney;
}

/*void Bank::payBank( Players &p1, int n )//make the player pay the bank for however much money
{
	p1.subtractMoney( n ); 
	bankMoney = bankMoney + n;
}*/

void Bank::payPlayer(Players &p1, int n )//make the bank pay the player for however much money
{

	p1.addMoney( n ); 
	bankMoney = bankMoney - n;

}
