#include "Room.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

void Game::createRooms()
{

    rooms.clear();

    rooms.push_back(Room("Outside", 0, 0, "Border", "Casino Entrance", "Parking Lot", "Border"));
    rooms.push_back(Room("Casino Entrance", 1, 0, "Border", "Casino Floor", "Border", "Outside"));
    rooms.push_back(Room("Casino Floor", 2, 0, "Slots", "Bar", "Tables", "Outside"));
    rooms.push_back(Room("Bar", 3, 0, "Bathrooms", "Bar Counter", "Bar Outside Exit", "Casino Floor"));
    rooms.push_back(Room("Slots", 2, 1, "Border", "Border", "Casino Floor", "Border"));
    rooms.push_back(Room("Bar Counter", 4, 0, "Border", "Border", "Border", "Bar"));
}

Room Game::getCurrentRoom(const std::string &room)
{
    auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room &r)
                           { return r.getName() == room; });

    if (it != rooms.end())
    {
        return *it;
    }

    throw std::runtime_error("Room '" + room + "' not found.");
}

void Game::roomChecks(Room curRoom, Player User)
{
    if (curRoom.getName() == "Slots")
    {
        slotMachine(User);
    }
    else if (curRoom.getName() == "Bar Counter")
    {
        bar(User);
    }
}