/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#ifndef ROOM_H
#define ROOM_H
#include <string>

class Room
{
private:
    std::string Name;
    std::string borderNorth;
    std::string borderEast;
    std::string borderSouth;
    std::string borderWest;

public:

    Room()
        : Name(""),
          borderNorth(""), borderEast(""),
          borderSouth(""), borderWest("") {}
          
    Room(std::string name, std::string N, std::string E,
         std::string S, std::string W)
    {
        Name = name;
        borderNorth = N;
        borderEast = E;
        borderSouth = S;
        borderWest = W;
    }

    std::string getName() const
    {
        return Name;
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
