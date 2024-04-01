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
    else if (curRoom.getName() == "Black Jack")
    {
        blackJack(User);
    }
}

Room Game::move(Room curRoom, Player User)
{

    while (true)
    {
        std::cout << "\n";
        if (!(curRoom.getN() == "Border"))
        {
            std::cout << "To your north is " << curRoom.getN() << "\n";
        }
        if (!(curRoom.getE() == "Border"))
        {
            std::cout << "To your east is " << curRoom.getE() << "\n";
        }
        if (!(curRoom.getS() == "Border"))
        {
            std::cout << "To your south is " << curRoom.getS() << "\n";
        }
        if (!(curRoom.getW() == "Border"))
        {
            std::cout << "To your west is " << curRoom.getW() << "\n";
        }

        std::cout << "\nEnter a direction (N/E/S/W):\n";
        std::string direction;
        std::cin >> direction;
        std::cout << "\n";

        if ((direction == "n" || direction == "N") && curRoom.getN() != "Border")
        {
            std::cout << "You walked north, over to " << curRoom.getN() << "...\n";
            return getCurrentRoom(curRoom.getN());
        }
        else if ((direction == "e" || direction == "E") && curRoom.getE() != "Border")
        {
            std::cout << "You walked east, over to " << curRoom.getE() << "...\n";
            return getCurrentRoom(curRoom.getE());
        }
        else if ((direction == "s" || direction == "S") && curRoom.getS() != "Border")
        {
            std::cout << "You walked south, over to " << curRoom.getS() << "...\n";
            return getCurrentRoom(curRoom.getS());
        }
        else if ((direction == "w" || direction == "W") && curRoom.getW() != "Border")
        {
            std::cout << "You walked west, over to " << curRoom.getW() << "...\n";
            return getCurrentRoom(curRoom.getW());
        }
        else if (direction == "i" || direction == "I")
        {
            User.getInfo();
        }
        else
        {
            // Invalid direction, prompt the user again
            std::cout << "Invalid direction. Please enter a valid direction.\n";
        }
    }
}