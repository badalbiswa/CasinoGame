#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Player.h"
#include <vector>

class Game
{
private:
std::vector<Room> rooms;
public:
   Game();
   void createRooms();
   Player createPlayer();
   Room getCurrentRoom(const std::string& room);
   void play();
};

#endif
