#include "Room.h"
#include "Game.h"
#include <iostream>
#include <algorithm>

void Game::createRooms()
{

    rooms.clear();


    rooms.push_back(Room("Outside", 0, 0, "Border", "Casino Floor", "Parking Lot", "Border"));
    rooms.push_back(Room("Casino Entrance", 1, 0, "Border", "Casino Floor", "Border", "Outside"));
    rooms.push_back(Room("Casino Floor", 2, 0, "Slots", "Bar", "Tables", "Outside"));
    rooms.push_back(Room("Bar", 3, 0, "Bathrooms", "Counter", "Bar Outside Exit", "Casino Floor"));
}


Room Game::getCurrentRoom(const std::string& room) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room& r) {
        return r.getName() == room;
    });

    if (it != rooms.end()) {
        return *it;
    }

    throw std::runtime_error("Room '" + room + "' not found.");
}
