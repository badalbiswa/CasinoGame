#ifndef ROOM_H
#define ROOM_H
#include <string>

class Room {
 private:
    std::string name;
 public:
    Room(const std::string& name);
    std::string getName() const;
};

#endif
