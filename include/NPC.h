/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

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
   NPC()
   : Name(""), Room(""), Money(0), Health(0), Dialog(""), Fightable (0){}
   NPC(std::string name, std::string room, int money, float hp, std::string dialog, bool fightable)
   {
      Name = name;
      Room = room;
      Money = money;
      Health = hp;
      Dialog = dialog;
      Fightable = fightable;
   }
   float getHealth(){
      return Health;
   }
   void setHealth(float health)
   {
      Health = health;
   }
   bool getFight(){
      return Fightable;
   }
   void setFight(bool fight)
   {
      Fightable = fight;
   }
};

#endif
