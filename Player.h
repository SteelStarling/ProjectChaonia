//
// Created by thanc on 11/18/22.
//

#ifndef PROJECTCHAONIA_PLAYER_H
#define PROJECTCHAONIA_PLAYER_H


#include "Object.h"
#include "Inventory.h"
#include "Room.h"

// The actual player
class Player {
private:
    Room* location;
    Inventory inventory;
public:
    /**
     * Creates a new player
     * @param location the location the player starts in
     */
    Player(Room& location) : location(&location), inventory("You are holding: ") {}

    /**
     * Gets the player's location
     * @return the Room the player is in
     */
    Room& getLocation() const { return *location; }

    /**
     * Sets the player's location
     * @param location the Room the player should be placed into
     */
    void setLocation(Room& location) { this->location = &location; }

    /**
     * Moves the player in the specified direction automatically
     * @param d the Direction to move in
     * @return boolean stating if the traversal was successful or not
     */
    bool traverse(Direction d);

    /**
     * Gets the inventory of the given room
     * @return the room's inventory
     */
    Inventory& getInventory () { return inventory; }

    /**
     * Picks up the given item and adds it to the inventory
     * @param item the item to pick up
     * NOTE: Does not work on triggers, which are designated as immovable objects
     */
    void pickUp(int item);

    /**
     * Sets down the given item and adds it to the room inventory
     * @param item the item to set down
     * NOTE: Does not work on triggers, which are designated as immovable objects
     */
    void setDown(int item);
};


#endif //PROJECTCHAONIA_PLAYER_H
