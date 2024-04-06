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
  sleep(2);
  std::cin >> input;
  std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
  if (input == "1") {
    User.addToInventory(Beer);
    std::cout << "*The Bartender served you a beer*\n";
    sleep(2);
    std::cout
        << "Beer has been added to inventory.\n";
        sleep(2);
        std::cout << "press I to access your inventory and drink the beer!\n";
    sleep(3);
  }
  std::cout << "\nYou have exited the " << curRoom.getName() << "...\n";
  User.updateRoom(getCurrentRoom(curRoom.getW()));
  curRoom = User.getRoom();
}

void Game::bathroom() {
  std::string input;
  if (BathroomDude.getFight()) {
  std::cout << "You notice a guy in the stalls smoking cigarettes\n";
  sleep(2);
  std::cout << "(1) Hey man you shouldnt be smoking in here\n"
  << "(2) Hey! Im the Casino Boss, pass over you cigarettes before I kick "
  << "you out of here!\n"
  << "(3) Do nothing\n";
  std::cin >> input;
  sleep(1);
  if (input == "1") {
    std::cout << "The man behind the stall door: Hey mind your own buisness!\n";
    sleep(2);
  } else if (input == "2") {
    std::cout << "The man behind the stall door: Im sorry, here take them!\n";
    sleep(2);
    std::cout << "*The guy passes you the cigarettes "
    << "underneath the stall door*\n";
    sleep(2);
    std::cout << "Cigarettes have been added to Inventory\n";
    User.addToInventory(Cigarette);
    BathroomDude.setFight(0);
    sleep(3);
  }
  }
}

void Game::lineCook() {
  std::string input;
  if (Linecook.getFight()) {
    std::cout
        << "*You exited the bar and you see a Linecook outside on his phone*\n";
        sleep(2);
        std::cout << "Linecook: Man I could go for a "
        << "cigarette, do you have any? "
        << "Ill trade you these brass knuckles for them\n";
        if (User.hasItem("Cigarettes")) {
          sleep(2);
        std::cout <<"(1) Give him your Cigarettes\n(2) Ignore his request\n";
        std::cin >> input;
        }
    if ((input == "1") && (User.hasItem("Cigarettes"))) {
      std::cout
          << "Linecook: Sweet, I've been craving a smoke all day.\n";
          sleep(2);
          std::cout << "*You gave the linecook your cigarettes and he "
          << "exchanged you a shiny pair of brass knuckles*\n";
          sleep(2);
          std::cout << "Brass Knuckes has been added to Inventory\n";
      User.addToInventory(BrassKnuckles);
      User.removeFromInventory(Cigarette);
      Linecook.setFight(0);
      sleep(3);
    } else {
      std::cout << "You: Sorry man, I dont have any.\n";
      sleep(2);
      std::cout << "Linecook: Nevermind then get lost pal\n";
      sleep(2);
    }
  } else {
    std::cout
        << "*You exited the bar and you see the "
        << "linecook smoking your cigarettes*\n";
  }
}

void Game::parkingLot() {
  std::string input;
  if (HomelessGuy.getFight()) {
    sleep(1);
    std::cout << "*You notice the homeless man chilling out here looking "
    << "at his chips*\n";
    sleep(2);
    std::cout << "You: Hey! I saw you earlier, running out of the "
    << "casino with those chips!!\n";
    sleep(2);
    std::cout << "Homeless Guy: No man you didn’t see anything.\n";
    sleep(2);
    std::cout << "You: Give me the chips now!!! I need those chips.\n";
    sleep(2);
    std::cout << "Homeless guy: Come fight me for it then bozo!\n";
    sleep(2);
    std::cout << "Would you like to fight him? (y/n)\n";
    std::cin >> input;
    if ((input == "y") || (input == "Y")) {
    std::cout << "*You start scuffling with the Homeless Guy*\n";
    sleep(2);
    std::cout << "Homeless Guy: You think I'm weak???\n";
    sleep(2);
    std::cout << "*The Homeless Guy pulls out a knife*\n";
    sleep(2);
      if (User.hasItem("Brass Knuckles")) {
        std::cout
        << "You: Yeah you are!\n";
        sleep(2);
        std::cout << "*You slip on your brass knuckles...*\n";
        sleep(2);
    std::cout << "You beat up the homeless guy with your "
    << "brass knuckles and knock "
            <<"him out cold!\n";
            sleep(2);
            std::cout << "You take his chips as you leave.\n";
            sleep(2);
            std::cout << "*You found 20,000 chips!*\n";
            sleep(2);
        User.setChips(User.getChips() + 20000);
        HomelessGuy.setFight(0);
      } else {
        std::cout
            << "You scuffled with the homeless guy and he "
            << "overpowered you with his knife and killed you...\n";
            sleep(2);
            std::cout << "YOU DIED\n";
            sleep(1);
        exit(0);
      }
    }
  } else if (User.hasItem("Unknown Device...")) {
    std::cout << "*You notice the homeless guy is out cold on the ground, "
    << "his hoodie pockets is a great place for hiding things...*\n";
    sleep(2);
    std::cout << "What would you like to do?\n";
    sleep(2);
    std::cout << "(1) Plant the Unknown Device on the Homeless Guy\n"
    << "(2) Do nothing\n";
    std::cin >> input;
    sleep(2);
    if (input == "1") {
      std::cout << "*You planted the Unknown Device on the Homeless Guy...*\n";
      User.removeFromInventory(UnknownDevice);
      sleep(2);
    }
  } else {
    std::cout << "*You notice the homeless guy is out cold on the ground.*";
    sleep(2);
  }
}

void Game::casinoBank() {
  int chips = User.getChips();
  int money = User.getMoney();

  if (BankTeller.getFight()) {
    sleep(2);
    std::cout
        << "Bank Teller: Hello! Welcome to the casino bank, "
        << "how can I help you?\n";
        sleep(2);
    if (money > 0)
      std::cout << "(1) Exchange money for chips\n";
    if (chips > 0)
      std::cout << "(2) Exchange chips for money\n";
    std::cout << "(3) Leave\n";
    std::string input;
    std::cin >> input;
  sleep(2);
    if (input == "1" && money > 0) {
      std::cout
          << "*You pass her your money*\n";
          sleep(2);
          std::cout << "Bank Teller: Okay! Here you go!\n";
          sleep(2);
      User.setChips(chips + money);
      std::cout << "*You got " << money << " chips*\n";
      User.setMoney(0);
      sleep(2);
    } else if (input == "2" && chips > 0) {
      std::cout
          << "*You pass her your chips*\n";
          sleep(2);
          std::cout << "Bank Teller: Okay! Here you go!\n";
      User.setMoney(money + chips);
      sleep(2);
      std::cout << "*You got $" << chips << "*\n";
      User.setChips(0);
      sleep(2);
    }
    std::cout << "You left the Casino Bank...\n";
    User.updateRoom(getCurrentRoom(curRoom.getS()));
    curRoom = User.getRoom();
    sleep(2);
  }
}

void Game::mobBoss() {
  std::string input;
  std::cout
      << "Casino Hacker: Hey, you! I saw you "
      << "beat up that homeless guy outside and and took all his chips.\n";
      sleep(2);
      std::cout << "Casino Hacker: Those chips belong to me!\n";
      sleep(2);
      std::cout << "Casino Hacker: That punk stole it from me "
      << "while I was cheating the slots!\n";
      sleep(2);
      std::cout << "Casino Hacker: They are mine so pass them over!\n";
    sleep(2);
  if (User.getChips() < 20000) {
    std::cout << "*You only have " << User.getChips() << "*\n";
    sleep(2);
       std::cout << "You: I kinda spent all of it...\n";
       sleep(2);
        std::cout << "Casino Hacker: They better have a damn good "
        << "janitor at the casino!\n";
        sleep(2);
        std::cout << "\n The Casino Hacker beat you into a pulp.\n";
        sleep(2);
        std::cout <<  "YOU DIED\n";
        sleep(1);
    exit(0);
  }
  std::cout
      << "(1) Return the chips to him\n(2) Ignore his "
      << "commands.\n";
      sleep(2);
  std::cin >> input;
  sleep(2);
  if ((input == "1") && User.getChips() >= 20000) {
    std::cout
      <<"*You gave the Casino Hacker 20,000 chips*";
      sleep(2);
      std::cout
        << "Casino Hacker: Good. He almost got away with "
        << "all my chips!\n";
        sleep(2);
        std::cout << "Casino Hacker: Here, I'll give you "
        << "something ive been working on, "
        << "I already have too much heat on me anyways...\n";
        sleep(2);
        std::cout << "Unknown Device... has been added to your inventory\n";
    User.addToInventory(UnknownDevice);
    MobBoss.setHealth(0);
    User.setChips(User.getChips() - 20000);
  } else {
    std::cout
        << "You: These chips are mine I risked my life for them!\n";
        sleep(2);
        std::cout << "Casino Hacker: I'll make sure the risk didn't pay off!\n"
        << "\n The Casino Hacker beat you into a pulp. \n YOU DIED\n";
    exit(0);
  }
}
