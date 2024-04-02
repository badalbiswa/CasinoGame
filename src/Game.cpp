#include "Game.h"
#include "Room.h"
#include "Player.h"
#include "NPC.h"
#include <iostream>
#include <sstream>

Game::Game() {
    createRooms();
    createNPCs();
    createItems();
}

void Game::play()
{
    // Game loop
    while (true)
    {
        curRoom = User.getRoom();
        roomChecks();
        move();
    }
}
