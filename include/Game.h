#ifndef GAME_H
#define GAME_H
#include "Room.h"

class Game {
 private:
    static const int WIDTH = 3; // Width of the game world
    static const int HEIGHT = 3; // Height of the game world
    Room* rooms[WIDTH][HEIGHT]; // 2D array of rooms
    int playerX, playerY; // Player's position in the game world
 public:
    Game();
    void play();
    void createRooms(); // Declaration of createRooms function
};

#endif

