//
// Created by Taylor Hancock on 11/19/22.
//

#ifndef PROJECTCHAONIA_INVENTORY_H
#define PROJECTCHAONIA_INVENTORY_H


#include "Object.h"

#include <vector>
#include <string>


class Inventory {
protected:
    // TODO: Implement weighted inventory class that limits max weights
    std::string holdDescription; // explains how the objects are held e.g. "you are holding" or "on the floor"
    std::vector<Object*> inventory;
public:
    /**
     * Creates a new inventory with the specified hold description
     * @param holdDesc a description of the way the inventory holds objects
     * NOTE: Example holdDesc's include "you are holding" or "on the floor"
     */
    Inventory(std::string holdDesc) : holdDescription(holdDesc) {}

    /**
     * Gets the inventory item at the specified location
     * @param item the index of the item to get
     * @return the item at the specified index
     * NOTE: Throws "Index Out of Bounds" exception if given invalid index
     */
    Object& getItem(int item);

    /**
     * Removes and returns the inventory item at the specified location
     * @param item the index of the item to get
     * @return the item at the specified index
     * NOTE: Throws "Index Out of Bounds" exception if given invalid index, or "Immovable Object" if given an
     *       Immovable Object such as a Trigger
     */
    Object& removeItem(int item);

    /**
     * Adds the specified item to the inventory
     * @param o the object to add to the inventory
     */
    void addItem(Object& o);

    /**
     * Gets a string holding the names of every item in the room
     * @return a string holding every item in the room separated by a newline
     */
    std::string getItemString() const;

    /**
     * Prints the contents of the player's inventory
     */
    void printInventory() const;
};


#endif //PROJECTCHAONIA_INVENTORY_H
