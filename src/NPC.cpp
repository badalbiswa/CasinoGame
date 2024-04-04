#include "NPC.h"
#include "Game.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <limits>

void Game::createNPCs()
{
    Bartender = NPC("Bartender", "Bar Counter", 100, 100, "Welcome to the bar!", 0);
    Dealer = NPC("Dealer", "BlackJack", 100, 100, "Take a seat and place your bets.", 0);
    HomelessGuy = NPC("Homeless Guy", "Parking Lot", 100, 100, "What are you looking at?", 1);
    Linecook = NPC("John the Linecook", "Bar Outside Exit", 100, 100, "Smoking a ciggy", 1);
    MobBoss = NPC ("Mob Boss", "Parking Lot", 100, 100, "Big Burly Guy", 1);

    std::cout << "*You walk up to the casino and a homeless man runs through the doors, looking"
    << "back to see if he was being chased out. He runs towards the parking lot.*\n";
}

void Game::bar(){
std::string input;

std::cout << "*You have sat down at the Bar*\n";
sleep(2); 
std::cout << "Bartender: Hey what can I grab for you?\nYou: ";
std::cin >> input;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
User.addToInventory(Beer);
std::cout << "*The Bartender served you a beer*\n";
sleep(2);
std::cout << "Beer has been added to inventory.\npress I to access your inventory and drink the beer!\n";
sleep(3);
std::cout << "\nYou have exited the " << curRoom.getName() << "...";
}

void Game::lineCook(){
std::string input;
if (Linecook.getFight()){
std::cout <<"*You exited the bar and you see a Linecook outside on his phone*\n";
std::cout <<"Linecook: Man i could go for a ciggy do you have any? Ill trade you these brass knuckles for them\n";
if (User.hasItem("Cigarettes"))
{
    std::cout <<"*You gave the linecook your cigarettes and he exchanged you a shiny pair of brass knuckles*\n";
    User.addToInventory(BrassKnuckles);
    User.removeFromInventory(Cigarette);
    Linecook.setFight(0);
} else
{
std::cout << "Linecook: Nevermind then get lost pal\n";
}
}
else {
    std::cout << "*You exited the bar and you see the linecook smoking your cigarettes\n";
}
}

void Game::parkingLot(){
std::string input;

if (HomelessGuy.getFight()){
std::cout << "*You notice the homeless man chilling out here*\n";
std::cout << "Would you like to fight him? (y/n)\n";
std::cin >> input;
if (input == "y") {
    if (User.hasItem("Brass Knuckles"))
    {
        std::cout << "You beat up the homeless guy with your brass knuckles and got 20,000 chips!\n";
        User.setChips(User.getChips() + 20000);
        HomelessGuy.setFight(0);
    } else
    {
        std::cout << "You scuffled with the homeless guy and he overpowered you and killed you\n"
        << "YOU DIED\n";
        exit(0);
    }
}
} else {
    std::cout << "*You notice the homeless guy is out cold on the ground*";
}
}