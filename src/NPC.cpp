#include "NPC.h"
#include "Game.h"
#include <iostream>
#include <string>

void Game::createNPCs()
{
    NPC Bartender = NPC("Bartender", "Bar Counter", 100, 100, "Welcome to the bar!", 0);
    NPC Dealer = NPC("Dealer", "BlackJack", 100, 100, "Take a seat and place your bets.", 0);
    NPC HomelessGuy = NPC("Homeless GUy", "Bar Outside Exit", 100, 100, "What are you looking at?", 0);
}

void Game::bar(Player User){

std::string input;

std::cout << "*You have sat down at the bar*\nBartender: Hey what can I grab for you?\n";
std::cin >> input;

}