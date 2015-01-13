#ifndef GAMEBOARD
#define GAMEBOARD
#include "players.h"

#include <iostream>
#include <sstream>
#include <iomanip> 
#include <QtGui>

using namespace std;

class GameBoard : public QWidget
{
Q_OBJECT
	private:
		/*static const int NUM_SPACES = 40;
		Space* spaces[NUM_SPACES];
		Action* actions[NUM_SPACES];
		House* houses[NUM_SPACES];
		Cards* cards[10]; 
		Players* players;	
		string pieces[10];
		int numPlayers;*/

		Players* players;	


		QLabel* boardLabel;
		QPixmap* dice;
    		QPushButton* diceButton;
	
	public: //prototyping the methods
		GameBoard();
		~GameBoard();
		/*void printTopRow(Space* sp[], Action* ac[], int x, int num, Players players[], MoneyAction a, GotoAction g, House h);
		void printBottomRow(Space* sp[], Action* ac[], int x, int num, Players players[], MoneyAction a, GotoAction g, House h);
		void printOtherRow(Space* sp[], Action* ac[], int x, int num, Players players[], MoneyAction a, GotoAction g, House h);
		Space** getSpaces();
		Action** getAction();
		bool onSpace(int spaceCheck, int numPlayers, Players players[], int position);
		string displayPlayer(int spaceCheck, int numPlayers, Players players[]);*/
		

};
#endif

