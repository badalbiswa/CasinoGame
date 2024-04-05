/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

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

class Game {
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
  NPC MobBoss;
  NPC BankTeller;
  NPC CasinoBoss;

 public:
  friend class Player;
  friend class Account;
  Game();
  void createRooms();
  void createNPCs();
  void createItems();
  Room getCurrentRoom(const std::string &room);
  void play();
  void bar();
  void casinoBank();
  void lineCook();
  void parkingLot();
  void mobBoss();
  int slotMachine();
  int blackJack();
  int roulette();
  int baccarate();
  void roomChecks();
  void move();
  void sleep(int time) {
    std::this_thread::sleep_for(std::chrono::seconds(time));
  }
};

#endif

