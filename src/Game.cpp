#include "Game.h"
#include "Room.h"
#include <iostream>
#include <sstream>

Game::Game() {}

void Game::play()
{
    // Game loop
    createRooms();
    while (true)
    {
        return;
        /*
        std::cout << "You are in ";
        // Get user input for direction
        std::cout << "Enter a direction (N/E/S/W): ";
        std::string direction;
        std::cin >> direction;
        // Update player position based on direction
        if ((direction == "n" || direction == "N") && playerY > 0) {
            playerY--;
        } else if ((direction == "e" || direction == "E")
        && playerX < WIDTH - 1) {
            playerX++;
        } else if ((direction == "s" || direction == "S")
        && playerY < HEIGHT - 1) {
            playerY++;
        } else if ((direction == "w" || direction == "W") && playerX > 0) {
            playerX--;
        } else {
            std::cout << "Invalid direction or boundary reached." << std::endl;
        }
        */
    }
}
