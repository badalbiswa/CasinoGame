/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include "Room.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

void Game::createRooms() {
  rooms.clear();

  rooms.push_back(
      Room("Outside", "Border", "Casino Entrance", "Parking Lot", "Border",
      "The casino entrance flashes with lights, "
      "and the parking lot is dimly lit.\n"));
  rooms.push_back(Room("Parking Lot", "Outside", "Border", "Border", "Border",
  "It looks very shady here, the dim lighting makes you uneasy.\n"));
  rooms.push_back(
      Room("Casino Entrance", "Casino Bank", "Casino Floor", "Border",
           "Outside", "You see a typical Casino Entrance, the noises from the "
           "machines bleeds into the room.\n"));
  rooms.push_back(
      Room("Casino Bank", "Border", "Border", "Casino Entrance", "Border",
      "You see the teller is behind the grate patiently waiting.\n"));
  rooms.push_back(
      Room("Casino Floor", "Slots", "Bar Entrance", "Tables", "Casino Entrance",
      "You see the heart of the Casino, people everywhere playing slots "
      "and table games.\n"));
  rooms.push_back(
      Room("Bar Entrance", "Bathrooms", "Bar Counter", "Bar Outside Exit",
           "Casino Floor", "This Bar reminds you of the one you run,"
           " very old fashioned but kept well.\n"));
  rooms.push_back(Room("Bar Counter", "Border", "Border",
  "Border", "Bar Entrance",
  "You notice the Bartender cleaning glasses.\n"));
  rooms.push_back(
      Room("Bar Outside Exit", "Bar Entrance", "Border", "Border", "Border",
      "You stand on a loading dock, a place meant for Bar workers to "
      "enjoy their breaks.\n"));
  rooms.push_back(Room("Slots", "Border", "Border",
  "Casino Floor", "Border", ""));
  rooms.push_back(
      Room("Tables", "Casino Floor", "Baccarate", "Black Jack", "Roulette",
      "You notice an area filled with a variety of tables, and lots "
      "of players.\n"));
  rooms.push_back(Room("Roulette", "Border", "Tables", "Border", "Border", ""));
  rooms.push_back(Room("Black Jack", "Tables",
  "Border", "Border", "Border", ""));
  rooms.push_back(Room("Baccarate", "Border",
  "Border", "Border", "Tables", ""));
  rooms.push_back(Room("Bathrooms", "Border", "Border",
  "Bar Entrance", "Border",
  "You are disgusted by the dilapidated and gross bathroom, "
  "you question when it was last cleaned.\n"));
}

Room Game::getCurrentRoom(const std::string &room) {
  auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room &r) {
    return r.getName() == room;
  });

  if (it != rooms.end()) {
    return *it;
  }

  throw std::runtime_error("Room '" + room + "' not found.");
}

void Game::roomChecks() {
  if (curRoom.getName() == "Slots") {
    if (User.getChips() > 0) {
      User.setChips(slotMachine());
    } else {
      std::cout << "*You don't have any chips to play casino games*\n"
          << "You have exited " << curRoom.getName() << "\n";
      User.updateRoom(getCurrentRoom(curRoom.getS()));
      curRoom = User.getRoom();
    }
  } else if (curRoom.getName() == "Black Jack") {
    if (User.getChips() > 0) {
      User.setChips(blackJack());
    } else {
      std::cout << "*You don't have any chips to play casino games*\n"
          << "You have exited " << curRoom.getName() << "\n";
      User.updateRoom(getCurrentRoom(curRoom.getN()));
      curRoom = User.getRoom();
    }
  } else if (curRoom.getName() == "Roulette") {
    if (User.getChips() > 0) {
      User.setChips(roulette());
    } else {
      std::cout << "*You don't have any chips to play casino games*\n"
          << "You have exited " << curRoom.getName() << "\n";
      User.updateRoom(getCurrentRoom(curRoom.getE()));
      curRoom = User.getRoom();
    }
  } else if (curRoom.getName() == "Baccarate") {
    if (User.getChips() > 0) {
      User.setChips(baccarate());
    } else {
      std::cout << "*You don't have any chips to play casino games*\n"
          << "You have exited " << curRoom.getName() << "\n";
      User.updateRoom(getCurrentRoom(curRoom.getW()));
      curRoom = User.getRoom();
    }
  } else if (curRoom.getName() == "Bar Counter") {
    bar();
  } else if (curRoom.getName() == "Bar Outside Exit") {
    lineCook();
  } else if (curRoom.getName() == "Parking Lot") {
    parkingLot();
  } else if (curRoom.getName() == "Casino Bank") {
    casinoBank();
  } else if (curRoom.getName() == "Bathrooms") {
    bathroom();
  } else if ((curRoom.getName() == "Casino Floor") && (!MobBoss.getFight())
      && (MobBoss.getHealth() != 0)) {
    mobBoss();
  } else if ((curRoom.getName() == "Outside") && (User.getMoney() >= 50000)) {
    std::string input;
    std::cout
        << "You are able to leave the casino now that you have over $50000\n"
        << "Would you like to leave?\n(1) Yes\n(2) No\n";
    std::cin >> input;
    if (input == "1") {
      std::cout
      << "You left the casino and were able to save your house...\nYOU WIN\n";
      exit(0);
    }
  }
}

void Game::move() {
  if ((User.getChips() == 0) && (User.getMoney() == 0)
  && (HomelessGuy.getFight() == 0)) {
    std::cout << "You completely ran out of money, and every way to get money, "
    << "you have no choice but to give up\n YOU LOSE\n";
    exit(0);
  }
srand(time(nullptr));
unsigned int seed = static_cast<unsigned int>(time(nullptr));
int randomNumber = rand_r(&seed) % 5 + 1;
if ((MobBoss.getFight()) && (randomNumber == 5) && (!HomelessGuy.getFight())) {
    std::cout << "You feel like you are being watched...\n";
    MobBoss.setFight(0);
}

  std::cout << "You are at " << curRoom.getName() << "\n\n";
  std::cout << curRoom.getDesc();
  while (true) {
    if (!(curRoom.getN() == "Border")) {
      std::cout << "To your north is " << curRoom.getN() << "\n";
    }
    if (!(curRoom.getE() == "Border")) {
      std::cout << "To your east is " << curRoom.getE() << "\n";
    }
    if (!(curRoom.getS() == "Border")) {
      std::cout << "To your south is " << curRoom.getS() << "\n";
    }
    if (!(curRoom.getW() == "Border")) {
      std::cout << "To your west is " << curRoom.getW() << "\n";
    }

    std::cout << "\nEnter a direction (N/E/S/W):\n";
    std::string direction;
    std::cin >> direction;

    if ((direction == "n" || direction == "N") && curRoom.getN() != "Border") {
      std::cout << "You walked north, over to " << curRoom.getN() << "...\n";
      User.updateRoom(getCurrentRoom(curRoom.getN()));
      return;
    } else if ((direction == "e" || direction == "E")
        && curRoom.getE() != "Border") {
      std::cout << "You walked east, over to " << curRoom.getE() << "...\n";
      User.updateRoom(getCurrentRoom(curRoom.getE()));
      return;
    } else if ((direction == "s" || direction == "S")
        && curRoom.getS() != "Border") {
      std::cout << "You walked south, over to " << curRoom.getS() << "...\n";
      User.updateRoom(getCurrentRoom(curRoom.getS()));
      return;
    } else if ((direction == "w" || direction == "W")
        && curRoom.getW() != "Border") {
      std::cout << "You walked west, over to " << curRoom.getW() << "...\n";
      User.updateRoom(getCurrentRoom(curRoom.getW()));
      return;
    } else if (direction == "i" || direction == "I") {
      User.getInfo();

    } else {
      // Invalid direction, prompt the user again
      std::cout << "Invalid direction. Please enter a valid direction.\n";
    }
  }
}
