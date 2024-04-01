#ifndef ROOM_H
#define ROOM_H
#include <string>

class Room
{
private:
    std::string Name;
    int RoomX;
    int RoomY;
    std::string borderNorth;
    std::string borderEast;
    std::string borderSouth;
    std::string borderWest;

public:

    Room()
        : Name(""), RoomX(0), RoomY(0),
          borderNorth(""), borderEast(""),
          borderSouth(""), borderWest("") {}
          
    Room(std::string name, int x, int y, std::string N, std::string E,
         std::string S, std::string W)
    {
        Name = name;
        RoomX = x;
        RoomY = y;
        borderNorth = N;
        borderEast = E;
        borderSouth = S;
        borderWest = W;
    }

    std::string getName() const
    {
        return Name;
    }

    int getX()
    {
        return RoomX;
    }

    int getY()
    {
        return RoomY;
    }

    std::string getN()
    {
        return borderNorth;
    }
    std::string getE()
    {
        return borderEast;
    }
    std::string getS()
    {
        return borderSouth;
    }
    std::string getW()
    {
        return borderWest;
    }
};

#endif
