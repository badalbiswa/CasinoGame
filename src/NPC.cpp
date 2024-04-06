/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include "NPC.h"
#include "Game.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <limits>

void Game::createNPCs() {
  Bartender = NPC("Bartender", "Bar Counter", 100, 100, "Welcome to the bar!",
                  0);
  Dealer = NPC("Dealer", "BlackJack", 100, 100,
               "Take a seat and place your bets.", 0);
  HomelessGuy = NPC("Homeless Guy", "Parking Lot", 100, 100,
                    "What are you looking at?", 1);
  Linecook = NPC("John the Linecook", "Bar Outside Exit", 100, 100,
                 "Smoking a ciggy", 1);
  MobBoss = NPC("Mob Boss", "Parking Lot", 100, 100, "Big Burly Guy", 1);
  BankTeller = NPC("Bank Teller", "Casino Bank", 100, 100,
                   "Welcome to the bank", 1);
  CasinoBoss = NPC("Casino Boss", "", 100, 100, "I am the boss", 1);
  BathroomDude = NPC("The guy behind stall door", "", 100, 100,
  "Smoking a ciggy", 1);
}

void Game::bar() {
  std::string input;

  std::cout << "*You have sat down at the Bar*\n";
  sleep(2);
  std::cout << "Bartender: Hey what can I grab for you?\n(1) Beer\n";
  std::cin >> input;
  std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
  if (input == "1") {
    User.addToInventory(Beer);
    std::cout << "*The Bartender served you a beer*\n";
    sleep(2);
    std::cout
        << "Beer has been added to inventory.\npress I to "
        << "access your inventory and drink the beer!\n";
    sleep(3);
  }
  std::cout << "\nYou have exited the " << curRoom.getName() << "...\n";
  User.updateRoom(getCurrentRoom(curRoom.getW()));
  curRoom = User.getRoom();
}

void Game::bathroom() {
  std::string input;

  std::cout << "You notice a guy in the stalls smoking cigarettes\n"
  << "(1) Hey man you shouldnt be smoking in here\n"
  << "(2) Hey! Im the Casino Boss, pass over you cigarettes before I kick "
  << "you out of here!\n"
  << "(3) Do nothing\n";
  std::cin >> input;
  if (input == "1") {
    std::cout << "The man behind the stall door: Hey mind your own buisness!\n";
  } else if (input == "2") {
    std::cout << "The man behind the stall door: Im sorry, here take them!\n"
    << "*The guy passes you the cigarettes underneath the stall door*\n"
    << "Cigarettes have been added to Inventory\n";
    User.addToInventory(Cigarette);
  }
}

void Game::lineCook() {
  //std::string input;
  if (Linecook.getFight()) {
    std::cout
        << "*You exited the bar and you see a Linecook outside on his phone*\n";
    std::cout
        << "Linecook: Man i could go for a ciggy do you have any? "
        << "Ill trade you these brass knuckles for them\n";
    if (User.hasItem("Cigarettes")) {
      std::cout
          << "*You gave the linecook your cigarettes and he "
          << "exchanged you a shiny pair of brass knuckles*\n";
      User.addToInventory(BrassKnuckles);
      User.removeFromInventory(Cigarette);
      Linecook.setFight(0);
    } else {
      std::cout << "Linecook: Nevermind then get lost pal\n";
    }
  } else {
    std::cout
        << "*You exited the bar and you see the "
        << "linecook smoking your cigarettes\n";
  }
}

void Game::parkingLot() {
  std::string input;

  if (HomelessGuy.getFight()) {
    std::cout << "*You notice the homeless man chilling out here*\n";
    std::cout << "Would you like to fight him? (y/n)\n";
    std::cin >> input;
    if (input == "y") {
      if (User.hasItem("Brass Knuckles")) {
        std::cout
            << "You beat up the homeless guy with your brass "
            << "knuckles and got 20,000 chips!\n";
        User.setChips(User.getChips() + 20000);
        HomelessGuy.setFight(0);
      } else {
        std::cout
            << "You scuffled with the homeless guy and he "
            << "overpowered you and killed you\n"
            << "YOU DIED\n";
        exit(0);
      }
    }
  } else {
    std::cout << "*You notice the homeless guy is out cold on the ground*";
  }
}

void Game::casinoBank() {
  int chips = User.getChips();
  int money = User.getMoney();

  if (BankTeller.getFight()) {
    std::cout
        << "Bank Teller: Hello! Welcome to the casino bank, "
        << "how can I help you?\n";
    if (money > 0)
      std::cout << "(1) Exchange money for chips\n";
    if (chips > 0)
      std::cout << "(2) Exchange chips for money\n";
    std::cout << "(3) Leave\n";
    std::string input;
    std::cin >> input;

    if (input == "1" && money > 0) {
      std::cout
          << "*You pass her your money*\nBank Teller: Okay! Here you go!\n";
      User.setChips(chips + money);
      std::cout << "*You got " << money << " chips*\n";
      User.setMoney(0);
    } else if (input == "2" && chips > 0) {
      std::cout
          << "*You pass her your chips*\nBank Teller: Okay! Here you go!\n";
      User.setMoney(money + chips);
      std::cout << "*You got $" << chips << "*\n";
      User.setChips(0);
    }

    std::cout << "You left the Casino Bank...\n";
    User.updateRoom(getCurrentRoom(curRoom.getS()));
    curRoom = User.getRoom();
  }
}

void Game::mobBoss() {
  std::string input;
  std::cout
      << "Mob Boss: Hey, you! One of my boys saw ricardo "
      << "beaten up outside and he said you took all his chips."
      << "That punk stole it from me while player poker, "
      << "they are mine so pass them over!\n";
  if (User.getChips() < 20000) {
    std::cout << "You only have " << User.getChips()
        << "\nYou: I kinda spent all of it...\n"
        << "Mob Boss: They better have a damn good janitor at the casino."
        << "\n The Mob Boss beat you into a pulp. \n YOU DIED\n";
    exit(0);
  }
  std::cout
      << "(1) Return the chips to him\n(2) Ignore his "
      << "commands.\n Your choice: ";
  std::cin >> input;
  if ((input == "1") && User.getChips() >= 20000) {
    std::cout
        << "Good. He almost got away if it wasnt for you, here ill "
        << "give you something ive been working on.\n"
        << "Unknown Device... has been added to your inventory\n";
    User.addToInventory(UnknownDevice);
    MobBoss.setHealth(0);
    User.setChips(User.getChips() - 20000);
  } else {
    std::cout
        << "Mob Boss:They better have a damn good janitor at the casino."
        << "\n The Mob Boss beat you into a pulp. \n YOU DIED\n";
    exit(0);
  }
}
