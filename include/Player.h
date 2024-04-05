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
       : Name(""), Chips(0), Money(10000),
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
                <<"\nMoney: $"<< Money << "\nChips: " << Chips << "\nHealth: " << Health << "\nThirst: " << Thirst
                << "\nDrunkness: " << Drunkness << "\nItems: ";
      listInventory();
      std::cout << "\n";
      checkItems();
   }

   int getChips()
   {
      return Chips;
   }

   void setChips(int chips)
   {
      Chips = chips;
   }
   int getMoney()
   {
      return Money;
   }
   void setMoney(int money)
   {
      Money = money;
   }

   void addToInventory(const Item &item)
   {
      inventory.addItem(item);
   }

   void removeFromInventory (const Item &item)
   {
      inventory.removeItem(item);
   }

   void listInventory() const
   {
      const std::vector<Item> &items = inventory.getItems();
      for (const Item &item : items)
      {
         std::cout << "\n" << item.getName() << "\n";
      }
   }

   void checkItems()
   {
      if (inventory.isEmpty()) {return;}
      std::string input;
      const std::vector<Item> &items = inventory.getItems();
      for (const Item &item : items)
      {
         if (item.getName() == "Beer")
         {
            std::cout << "Press 1 to drink the beer\n";
         }
         if (item.getName() == "Cigarettes")
         {
            std::cout << "Press 2 to smoke a cigarette\n";
         }
         if (item.getName()== "Brass Knuckles")
         {
         }

      }
   }
   bool hasItem(std::string Citem)
   {
      const std::vector<Item> &items = inventory.getItems();
      for (const Item &item : items)
      {
         if (item.getName() == Citem)
         {
            return true;
         }

      }  
      return false;    
   }
    
   };

#endif
