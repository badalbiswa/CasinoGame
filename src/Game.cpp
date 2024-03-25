#include "Game.h"
#include "Room.h"
#include <iostream>
#include <sstream> // For std::stringstream

Game::Game() {
    // Create rooms and populate the game world
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            std::stringstream ss;
            ss << "Room(" << x << "," << y << ")"; // Construct room name
            rooms[x][y] = new Room(ss.str());
        }
    }
    // Set initial player position
    playerX = 0;
    playerY = 0;
    createRooms();
}

void Game::createRooms() {
    // Create rooms and set names
    rooms[0][0] = new Room("Starting Room");
    rooms[1][0] = new Room("Casino Floor");
    // Add more rooms with appropriate names as needed
}

void Game::play() {
    // Game loop
    while (true) {
        std::cout << "You are in "
        << rooms[playerX][playerY]->getName() << std::endl;
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
    }
}

