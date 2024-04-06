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
#include <ctime>  // For time(), clock(), and CLOCKS_PER_SEC
#include <string>

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
  NPC BathroomDude;

 public:
  friend class Player;
  friend class Account;
  Game();
  void startUpInfo();
  void createRooms();
  void createNPCs();
  void createItems();
  Room getCurrentRoom(const std::string &room);
  void play();
  void bar();
  void casinoBank();
  void lineCook();
  void parkingLot();
  void bathroom();
  void mobBoss();
  int slotMachine();
  int blackJack();
  int roulette();
  int baccarate();
  void roomChecks();
  void move();
  void sleep(int time) {
    clock_t start_time = clock();  // Get the current clock time
    while ((clock() - start_time) / CLOCKS_PER_SEC < time){}
  }
};

#endif

