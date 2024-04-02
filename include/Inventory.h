#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <string>
#include <map>
#include "Item.h"

class Inventory
{
private:
    std::vector<Item> items;

public:
    void addItem(const Item& newItem) {
        items.push_back(newItem);
    }
    const std::vector<Item>& getItems() const {
        return items;
    }

};

#endif
