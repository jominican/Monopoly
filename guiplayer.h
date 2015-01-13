#include <QtGui>

#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include "players.h"

class GUIPlayer : public QDockWidget {
  Q_OBJECT

  protected:
    Players* players[4];
    QLabel *nameLabel[4];
   QLabel *moneyLabel[4];

  public:
    GUIPlayer( Players* p1, Players* p2, Players* p3, Players* p4  );
	void callLabel();

};

#endif
