#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "Item.h"
#include "Room.h"

class Room;

class Player
{
private:
   std::string Name;
   int Chips;
   int Money;
   float Health;
   float Thirst;
   float Drunkness;
   Room CurrentRoom;
   std::vector<Item> Items;

public:

   Player()
           : Name(""), Chips(20000), Money(20000),
          Health(100), Thirst(100), Drunkness(0),
          CurrentRoom("Outside", "Border", "Casino Entrance", "Parking Lot", "Border") {}

   Room getRoom()
   {
      return CurrentRoom;
   }

   void updateRoom(Room room)
   {
      CurrentRoom = room;
   }

   void getInfo()
   {
      std::cout << "You checked your stats...\n\nCurrent Location: "<< CurrentRoom.getName()<<"\nChips: " << Chips << "\nHealth: " << Health << "\nDrunkness: " << Drunkness << "\n";
   }

   int getChips()
   {
      return Chips;
   }

   void setChips(int chips)
   {
      Chips = chips;
   }
   
};

#endif
