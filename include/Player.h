#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "Item.h"
#include "Room.h"
#include "Inventory.h"

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
   Inventory inventory;

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
      std::cout << "You checked your stats...\n\nCurrent Location: " << CurrentRoom.getName()
      << "\nChips: " << Chips << "\nHealth: " << Health << "\nThirst: " << Thirst
      << "\nDrunkness: " << Drunkness << "\nItems: "; listInventory(); std::cout << "\n";
   }

   int getChips()
   {
      return Chips;
   }

   void setChips(int chips)
   {
      Chips = chips;
   }

    void addToInventory(const Item& item) {
        inventory.addItem(item);
    }

        void listInventory() const {
        const std::vector<Item>& items = inventory.getItems();
        for (const Item& item : items) {
            std::cout << "- " << item.getName() << "\n";
        }
    }
};

#endif
