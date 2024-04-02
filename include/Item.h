#ifndef ITEM_H
#define ITEM_H
#include <vector>
#include <string>

class Item
{
private:
std::string Name;
std::string Description;
float Price;
public:

Item()
:Name(""), Description(""), Price(0){};

Item(std::string name, std::string description, int price)
{
    Name = name;
    Description = description;
    Price = price;
}

std::string getName() const { return Name; }

};

#endif
    