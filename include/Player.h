#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

class Player
{
private:
   std::string Name;
   int Chips;
   int Money;
   float Health;
   float Thirst;
   float Drunkness;
   int PlayerX;
   int PlayerY;
   std::string Room;

public:
   Player(std::string name, int chips, int money, int hp, int thirst, int drunk, int x, int y, std::string room)
   {
      Name = name;
      PlayerX = x;
      PlayerY = y;
      Chips = chips;
      Money = money;
      Health = hp;
      Thirst = thirst;
      Drunkness = drunk;
      Room = room;
   }

   int getX()
   {
      return PlayerX;
   }

   int getY()
   {
      return PlayerY;
   }

   std::string getRoom()
   {
      return Room;
   }

   void setPosition(int x, int y)
   {
      PlayerX = x;
      PlayerY = y;
   }

   void updateRoom(std::string room)
   {
      Room = room;
   }

   void getInfo()
   {
      std::cout << "Your Stats\nChips: " << Chips << "\nHealth: " << Health << "\nDrunkness: " << Drunkness << "\n";
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
