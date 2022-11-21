
//
// Created by Taylor Hancock on 11/19/22.
//

#include "Inventory.h"
#include "Trigger.h"

Object& Inventory::getItem(int item) {
    if(item >= inventory.size() || item < 0) {
        throw std::string("Index Out of Bounds");
    }

    return *inventory.at(item);
}

Object& Inventory::removeItem(int item) {
    if(item >= inventory.size() || item < 0) { // handle out of bounds
        throw std::string("Index Out of Bounds");
    }

    Object& o = *inventory.at(item);

    if(typeid(o) == typeid(Trigger)) { // handle immovable objects TODO: Update later to actually have Immovable class
        throw std::string("Immovable Object");
    }

    inventory.erase(inventory.begin() + item); // delete specified element

    return o;
}

void Inventory::addItem(Object& o) {
    inventory.push_back(&o);
}

std::string Inventory::getItemString() const {
    std::string itemString = ""; // start with empty string to fill

    // Note: endl was being weird, so we're just using \n here

    if(inventory.empty()) { // only print if big enough
        itemString += holdDescription + "\n"; // print description

        for(int i = 0; i < inventory.size(); i++) {
            itemString += "    " + std::to_string(i) + ". " + (*inventory.at(i)).getName() + "\n";
        }
    }

    return itemString;
}

void Inventory::printInventory() const {
    std::cout << getItemString();
}