#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Player.h"
#include <vector>
#include <sstream>

class Game
{
private:
   std::vector<Room> rooms;

public:
   Game();
   void createRooms();
   //Player createPlayer();
   void createNPCs();
   Room getCurrentRoom(const std::string &room);
   void play();
   void slotMachine(Player User);
   void bar(Player User);
   void roomChecks(Room curRoom, Player User);
   void blackJack(Player User);
   Room move(Room curRoom, Player User);
};

#endif
