#include <QtGui>
#include <QObject>

#include "guiplayerhorizontal.h"
#include "guiplayervertical.h"
#include "gameBoard.h"
#include "players.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

class MainWindow : public QMainWindow {
  Q_OBJECT

  private://declaration types
	int xpos[40];
	int ypos[40];
	int currentPos[4] = {39,39,39,39};
	//GUISpace* spaces[40];
  QLabel *boardLabel;
  Players* players[4];
  GUIPlayer* guiPlayers[4];
  QPushButton* cardDeckButton;
  QPushButton* cardDeckButton1;
	//QPushButton* play;
	QPushButton* numPlayers[5];
  QWidget* centralWidget;

	QPixmap* dice[6];
	QPixmap* card[9];
	QPixmap* card1[9];
  QPushButton* diceButton[4];
  bool isDice;
	int upgrade[11];
	int upgradeCount[11];

  QLabel *nameLabel[4];
  QLabel *moneyLabel[4];
	QLabel *numLabel[4];
	int counter;
	QPixmap* piece[10];
	QPushButton* selectPiece[10];
	bool isPlayer[10];
	bool isFaceDown, isFaceDown1;
	bool choose1 = false, choose2 = false, choose3 =false, choose4=false;
	bool playerChoice[4];

	int a;
	int p[4];
	QSignalMapper* signalMapper;
		
	signals:
		//void choosePlayer(int);

  public slots://public functions
	void drawCard( QPushButton* n );
	void drawCard1( QPushButton* n);
	void goRandom(QPushButton* n);
	void resign();
	void buyHouse(QPushButton* n);
		void playerOne();
		void playerTwo();
		void playerThree();
		void playerFour();
	void checkLoss();
    void randomNum();
    void randomNum1();
    void randomNum2();
    void randomNum3();
		void chooseCard();
		void chooseCard1();
		//void choosePlayer2();
		//void choosePlayer3();
		//void choosePlayer4();
		void choosePlayer(int);
		void payMoney(int n);

	//public signals:
		//void mySignal(int n);

  public:
    MainWindow();

};
