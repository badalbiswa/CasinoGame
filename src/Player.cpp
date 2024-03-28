#include "Player.h"
#include "Game.h"
#include <iostream>

Player Game::createPlayer()
{
Player User = Player("Dude", 20000, 20000, 100, 100, 0, 0, 0, "Outside");
return User;
}
