#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <string>
#include <map>
#include "Item.h"
#include <algorithm>
 
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
    const Item* getItemByName(const std::string& name) const {
    for (const Item& item : items) {
        if (item.getName() == name) {
            return &item;
        }
    }
    return nullptr; // Item not found
}
void removeItemByName(const std::string& name) {
    auto it = std::remove_if(items.begin(), items.end(), [&](const Item& item) {
        return item.getName() == name;
    });
    items.erase(it, items.end());
}

};

#endif
