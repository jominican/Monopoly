#include "gameBoard.h"

GameBoard::GameBoard(): QWidget()
{

  //setGeometry( 0, 0, 577, 577 );
  boardLabel = new QLabel( this );//the main board image
  boardLabel->setPixmap( QPixmap("PA6.png") );

	/*dice = new QPixmap("dice.png");
  diceButton = new QPushButton( this );
  diceButton->setIcon( *dice );
  diceButton->setIconSize( QSize(152, 97) );
  diceButton->setGeometry( 240, 205, 152, 97);*/


}

GameBoard::~GameBoard()//deallocating the space array
{

}


