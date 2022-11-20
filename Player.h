//
// Created by thanc on 11/18/22.
//

#ifndef PROJECTCHAONIA_PLAYER_H
#define PROJECTCHAONIA_PLAYER_H


#include "Object.h"
#include "Room.h"

// The actual player
class Player {
private:
    Room& location;
    std::vector<Object> inventory;
public:
    Player(Room& location) : location(location) {}

    /**
     * Gets the player's location
     * @return the Room the player is in
     */
    Room& getLocation() const {
        return location;
    }

    /**
     * Sets the player's location
     * @param location the Room the player should be placed into
     */
    void setLocation(Room& location) {
        Player::location = location;
    }

    /**
     * Moves the player in the specified direction automatically
     * @param d the Direction to move in
     * @return boolean stating if the traversal was successful or not
     */
    bool traverse(Direction d) {
        Room& r = location;

        try {
            r = location.getConnection(d).traverse(); // try traversing
        } catch(std::string errMsg) {
            if(errMsg == std::string("Index Out of Bounds")) { // handle out of bounds
                std::cout << "...whatever direction you just input isn't...real...sadly, this game does not allow you to move into the 4th dimension, so please try again." << std::endl;
            } else if(errMsg == std::string("Invalid Direction")) { // handle directions that are empty
                std::cout << "The direction you input doesn't lead to a passageway." << std::endl << "You seem to remember being told in your youth to never leave the trail, presumably this must be similar, please try again." << std::endl;
            }

            return false;
        }

        location = r; // update location
    }

    /**
     * Gets the inventory item at the specified location
     * @param item the index of the item to get
     * @return the item at the specified index
     * NOTE: Throws "Index Out of Bounds" exception if given invalid index
     */
    Object& getItem(int item) {
        if(item >= inventory.size() || item < 0) {
            throw std::string("Index Out of Bounds");
        }

        return inventory.at(item);
    }

    /**
     * Removes and returns the inventory item at the specified location
     * @param item the index of the item to get
     * @return the item at the specified index
     * NOTE: Throws "Index Out of Bounds" exception if given invalid index
     */
    Object& removeItem(int item) {
        if(item >= inventory.size() || item < 0) {
            throw std::string("Index Out of Bounds");
        }

        Object& o = inventory.at(item);
        inventory.erase(inventory.begin() + item); // delete specified element

        return o;
    }

    /**
     * Prints the contents of the player's inventory
     */
    void printInventory() const {
        std::cout << "You are holding:" << std::endl;

        for(int i = 0; i < inventory.size(); i++) {
            std::cout << "    " << i << ". " << inventory.at(i).getName() << std::endl;
        }
    }

    void addItem(Object& o) {
        inventory.push_back(o);
    }

    /**
     * Picks up the given item and adds it to the inventory
     * @param item the item to pick up
     */
    void pickUp(int item) {
        Object* o = nullptr;

        try {
            o = &location.removeItem(item);
        } catch(std::string errMsg) {
            std::cout << "There is no matching item, please try a different command." << std::endl;

            return; // stop running
        }

        // add only if valid
        if(o != nullptr) {
            addItem(*o);
        }
    }

    void setDown(int item) {
        Object* o = nullptr;

        try {
            o = &removeItem(item);
        } catch(std::string errMsg) {
            std::cout << "There is no matching item, please try a different command." << std::endl;

            return; // stop running
        }

        // add only if valid
        if(o != nullptr) {
            location.addItem(*o);
        }
    }
};


#endif //PROJECTCHAONIA_PLAYER_H
