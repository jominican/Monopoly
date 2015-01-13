#ifndef PLAYERS
#define PLAYERS
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <QtGui>
#include <QString>


using namespace std;

class Players : public QWidget
{
 Q_OBJECT
	private:
		int currentPos;
		QString name;
		int money;


		/*QLabel* boardLabel;
		QPixmap* dice;
   		QPushButton* diceButton;
   		bool isDice;*/
  		
	public slots:
		//void addMoney(int amount);
	
	public:
		Players(QString n);
		~Players();
		int movePosition();
		int setPosition();
		int getPosition();
		int setNewPosition(int newSpace);
		QString getName();
		void setName(QString n);
		//void addMoney(int amount);
		void subtractMoney(int amount);
		void setMoney(int n);
		int getMoney();	
		void addMoney(int amount);
	
		
		

};
#endif

