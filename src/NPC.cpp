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