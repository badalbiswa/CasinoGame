#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Player.h"
#include "Item.h"
#include "NPC.h"
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>

class Game
{
private:
   Player User;
   Room curRoom;
   std::vector<Room> rooms;
   Item Beer;
   Item Cigarette;
   Item BrassKnuckles;
   Item UnknownDevice;
   NPC Bartender;
   NPC Dealer;
   NPC HomelessGuy;
   NPC Linecook;

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
   void sleep(int time)
   {
      std::this_thread::sleep_for(std::chrono::seconds(time));
   }
};

#endif
