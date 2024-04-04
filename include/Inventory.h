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
    bool isEmpty(){
        return items.empty();
    }
    void removeItem(const Item& itemToRemove) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == itemToRemove) {
            items.erase(it);
            return; // Exit the function after removing the item
        }
    }
    }

};

#endif
