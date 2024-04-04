#include "Room.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

void Game::createRooms()
{

    rooms.clear();

    rooms.push_back(Room("Outside", "Border", "Casino Entrance", "Parking Lot", "Border"));
    rooms.push_back(Room("Parking Lot", "Outside", "Border", "Border", "Border"));
    rooms.push_back(Room("Casino Entrance", "Border", "Casino Floor", "Border", "Outside"));
    rooms.push_back(Room("Casino Floor", "Slots", "Bar", "Tables", "Outside"));
    rooms.push_back(Room("Bar", "Bathrooms", "Bar Counter", "Bar Outside Exit", "Casino Floor"));
    rooms.push_back(Room("Bar Counter", "Border", "Border", "Border", "Bar"));
    rooms.push_back(Room("Bar Outside Exit", "Bar", "Border", "Border", "Border"));
    rooms.push_back(Room("Slots", "Border", "Border", "Casino Floor", "Border"));
    rooms.push_back(Room("Tables", "Casino Floor", "Baccarate", "Black Jack", "Roulette"));
    rooms.push_back(Room("Roulette", "Border", "Tables", "Border", "Border"));
    rooms.push_back(Room("Black Jack", "Tables", "Border", "Border", "Border"));
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

void Game::roomChecks()
{
    if (curRoom.getName() == "Slots")
    {
        User.setChips(slotMachine());
    }
    else if (curRoom.getName() == "Bar Counter")
    {
        bar();
    }
    else if (curRoom.getName() == "Black Jack")
    {
        User.setChips(blackJack());
    }
    else if (curRoom.getName() == "Roulette")
    {
        User.setChips(roulette());
    }
    else if (curRoom.getName() == "Bar Outside Exit")
    {
        lineCook();
    }
    else if (curRoom.getName() == "Parking Lot")
    {
        parkingLot();
    }
    else if ((curRoom.getName() == "Casino Floor") && (!MobBoss.getFight()) && (MobBoss.getHealth() != 0))
    {
        mobBoss();
    }
}

void Game::move()
{
    srand(time(nullptr));
    int randomNumber = rand() % 5 + 1;
    if ((MobBoss.getFight()) && (randomNumber == 5) && (!HomelessGuy.getFight())) {
        std::cout << "You feel like you are being watched...\n";
        MobBoss.setFight(0);
    }

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
            User.updateRoom(getCurrentRoom(curRoom.getN()));
            return;
        }
        else if ((direction == "e" || direction == "E") && curRoom.getE() != "Border")
        {
            std::cout << "You walked east, over to " << curRoom.getE() << "...\n";
            User.updateRoom(getCurrentRoom(curRoom.getE()));
            return;
        }
        else if ((direction == "s" || direction == "S") && curRoom.getS() != "Border")
        {
            std::cout << "You walked south, over to " << curRoom.getS() << "...\n";
            User.updateRoom(getCurrentRoom(curRoom.getS()));
            return;
        }
        else if ((direction == "w" || direction == "W") && curRoom.getW() != "Border")
        {
            std::cout << "You walked west, over to " << curRoom.getW() << "...\n";
            User.updateRoom(getCurrentRoom(curRoom.getW()));
            return;
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