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
   void createNPCs();
   Room getCurrentRoom(const std::string &room);
   void play();
   void bar(Player User);
   int slotMachine(Player User);
   int blackJack(Player User);
   void roomChecks(Room curRoom, Player& User);
   void move(Room curRoom, Player& User);
};

#endif
