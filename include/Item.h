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

    bool operator==(const Item& other) const {
        // Compare the relevant attributes of the items
        // For example, if name uniquely identifies items:
        return Name == other.Name;
    }

};

#endif
    