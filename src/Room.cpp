#include "Room.h"

Room::Room(std::string name, int x, int y, std::string N, std::string E,
           std::string S, std::string W) {
    Name = name;
    locX = x;
    locY = y;
    borderNorth = N;
    borderEast = E;
    borderSouth = S;
    borderWest = W;
}

std::string Room::getName() const {
    return Name;
}