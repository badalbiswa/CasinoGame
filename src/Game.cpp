#include "Game.h"
#include "Room.h"
#include "Player.h"
#include <iostream>
#include <sstream>

Game::Game() {}

void Game::play()
{
    // Game loop
    createRooms();
    createNPCs();
    Player User;
    Room curRoom;
    while (true)
    {
        curRoom = User.getRoom();
        roomChecks(curRoom, User);
        User.updateRoom(move(curRoom, User));
    }
}
