#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Player.h"
#include "Item.h"
#include <vector>
#include <sstream>

class Game
{
private:
   Player User;
   Room curRoom;
   std::vector<Room> rooms;
   Item Beer;

public:
   Game();
   void createRooms();
   void createNPCs();
   void createItems();
   Room getCurrentRoom(const std::string &room);
   void play();
   void bar();
   int slotMachine();
   int blackJack();
   void roomChecks();
   void move();
};

#endif
