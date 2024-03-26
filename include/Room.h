#ifndef ROOM_H
#define ROOM_H
#include <string>

class Room {
 private:
    std::string Name;
    int locX;
    int locY;
    std::string borderNorth;
    std::string borderEast;
    std::string borderSouth;
    std::string borderWest;

 public:
  Room(std::string name, int x, int y, std::string N, std::string E,
    std::string S, std::string W) {
Name = name;
locX = x;
locY = y;
borderNorth = N;
borderEast = E;
borderSouth = S;
borderWest = W;
    }

void createRooms(); // Declaration of createRooms function
};

#endif
