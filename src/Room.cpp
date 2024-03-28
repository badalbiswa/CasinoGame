#include "Room.h"
#include "Game.h"
#include <iostream>

void Game::createRooms()
{
    Room Outside = Room("Outside", 0, 0,
                        "Border", "Casino Floor", "Parking Lot", "Borders");
    Room CasinoEntrance = Room("Casino Entrance", 1, 0,
                               "Border", "Casino Floor", "Border", "Outside");
    Room CasinoFloor = Room("Casino Floor", 2, 0,
                            "Slots", "Bar", "Tables", "Outside");
    Room Bar = Room("Casino Floor", 3, 0,
                    "Bathrooms", "Counter", "Bar Outside Exit", "Casino Floor");

}
