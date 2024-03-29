#ifndef NPC_H
#define NPC_H
#include <string>

class NPC
{
private:
   std::string Name;
   std::string Room;
   int Money;
   float Health;
   std::string Dialog;
   bool Fightable;

public:
   NPC(std::string name, std::string room, int money, float hp, std::string dialog, bool fightable)
   {
      Name = name;
      Room = room;
      Money = money;
      Health = hp;
      Dialog = dialog;
      Fightable = fightable;
   }
};

#endif
