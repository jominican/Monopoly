#include <QtGui>

#ifndef GUIPLAYERVERTICAL_H
#define GUIPLAYERVERTICAL_H

#include "players.h"
#include "guiplayer.h"

class GUIPlayerVertical : public GUIPlayer {
  Q_OBJECT

  private:
    Players* player;
		QPixmap* dice;
		QPushButton* diceButton;

 public:
    GUIPlayerVertical( Players* p1, Players* p2, Players* p3, Players* p4 );



};

#endif
