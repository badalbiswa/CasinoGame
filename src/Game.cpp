/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

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

void Game::play() {
  // Game loop
  while (true) {
    curRoom = User.getRoom();
    roomChecks();
    move();
  }
}
