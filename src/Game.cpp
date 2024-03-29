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
    Player User = createPlayer();

    while (true)
    {
        Room curRoom = getCurrentRoom(User.getRoom());
        roomChecks(curRoom, User);
        std::cout << "Player is in " << curRoom.getName() << std::endl;

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

        std::cout << "Enter a direction (N/E/S/W): ";
        std::string direction;
        std::cin >> direction;

        if ((direction == "n" || direction == "N") && curRoom.getN() != "Border")
        {
            User.updateRoom(curRoom.getN());
        }
        else if ((direction == "e" || direction == "E") && curRoom.getE() != "Border")
        {
            User.updateRoom(curRoom.getE());
        }
        else if ((direction == "s" || direction == "S") && curRoom.getS() != "Border")
        {
            User.updateRoom(curRoom.getS());
        }
        else if ((direction == "w" || direction == "W") && curRoom.getW() != "Border")
        {
            User.updateRoom(curRoom.getW());
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
