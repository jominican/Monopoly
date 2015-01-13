#include "players.h"

Players::Players(QString n): QWidget()
{
	//seeding
	name = n;
	srand(time(0));
	money = 0;

	/*dice = new QPixmap(":/images/dice.png");
  diceButton = new QPushButton( this );
  diceButton->setIcon( *dice );
  diceButton->setIconSize( QSize(152, 97) );
  diceButton->setGeometry( 240, 205, 97, 152);*/



}

Players::~Players()//constructor
{

}

QString Players::getName()//get player name
{

	return name;
}

void Players::setName(QString choice)//set player name
{
	name = choice;
}

void Players::setMoney(int n)//set money for player
{
	money = n;

}

int Players::getMoney()//get current amount of money
{
	return money;
}

void Players::addMoney(int amount)//add money to player
{

		money = money + amount; 

}

void Players::subtractMoney(int amount)//subtract money from player
{
	if (money > 0){
		money = money - amount;
	}
}

