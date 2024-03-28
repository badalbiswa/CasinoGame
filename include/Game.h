#ifndef GAME_H
#define GAME_H
#include "Room.h"

class Game
{
private:
public:
   Game();
   void createRooms();
   Player createPlayer();
   void play();
};

#endif
