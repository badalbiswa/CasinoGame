#ifndef ROOM_H
#define ROOM_H
#include <string>

class Room {
 private:
    std::string name;
    int locX;
    int locY;

 public:
    Room(const std::string& name);
    std::string getName() const;
};

#endif
