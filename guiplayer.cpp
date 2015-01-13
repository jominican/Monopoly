#include "guiplayer.h"

GUIPlayer::GUIPlayer( Players* p1, Players* p2, Players* p3, Players* p4  ){
  players[0] = p1;
  players[1] = p2;
  players[2] = p3;
  players[3] = p4;

	for (int x; x<4; x++){
		nameLabel[x] = new QLabel( this );
		nameLabel[x]->setText( players[x]->getName() );
		//nameLabel->setText( players->getName() );
		moneyLabel[x] = new QLabel( this);
		moneyLabel[x]->setText( QString::number(players[x]->getMoney()));
	}
		nameLabel[0]->setGeometry(0,0,40,40);
		nameLabel[1]->setGeometry(0,30,40,40);
		nameLabel[2]->setGeometry(0,60,40,40);
		nameLabel[3]->setGeometry(0,90,40,40);
		moneyLabel[0]->setGeometry(15, 15, 40, 40);
		moneyLabel[1]->setGeometry(15, 45, 40, 40);
		moneyLabel[2]->setGeometry(15, 75, 40, 40);
		moneyLabel[3]->setGeometry(15, 105, 40, 40);


}

void GUIPlayer::callLabel()
{
	for (int x=0; x<4; x++){
	moneyLabel[x]->setText( QString::number(players[x]->getMoney()));
	}	
}
