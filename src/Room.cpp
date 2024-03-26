#include "Room.h"

//void createRooms() {
    Room CasinoFloor = Room("Casino Floor", 1, 1,
    "Slots", "Bar", "Tables", "Outside");
    Room Bar = Room("Casino Floor", 2, 1,
    "Bathrooms", "Counter", "Bar Outside Exit", "Casino Floor");
    Room Outside = Room("Outside", 2, 1,
    "Border", "Casino Floor", "Parking Lot", "Borders");
//}
