#include <QtGui>

#ifndef GUIPLAYERHORIZONTAL_H
#define GUIPLAYERHORIZONTAL_H

#include "players.h"
#include "guiplayer.h"

class GUIPlayerHorizontal : public GUIPlayer {
  Q_OBJECT

  private:

 public:
    GUIPlayerHorizontal( Players* p1, Players* p2, Players* p3, Players* p4 );

};

#endif
