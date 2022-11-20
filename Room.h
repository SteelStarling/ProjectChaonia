//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_ROOM_H
#define PROJECTCHAONIA_ROOM_H


#include "Object.h"
#include "Connection.h"
#include "Inventory.h"

enum Direction {
    NORTH,
    NORTHEAST,
    EAST,
    SOUTHEAST,
    SOUTH,
    SOUTHWEST,
    WEST,
    NORTHWEST,
    UP,
    DOWN,
    NUM_DIR // holds number of directions for maxval checking
};

class Room : public Object {
private:
    Inventory inventory; // holds all items present in the room
    Connection* connections[NUM_DIR]; // holds all connections
public:

    /**
     * Creates a new room with no items or connections
     * @param name the name of the room
     * @param description the description of the room
     */
    Room(std::string name, std::string description);

    //NOTE: We only handle pointers here, because we want to ensure that objects cannot be destroyed without good reason - All objects are stored in the Object Master List held by the game itself.

    /**
     * Sets the connection in the direction
     * @param d the direction to set the connection in
     * @param c the connection to set
     * NOTE: Throws Index Out of Bounds exception if given non-enum specified direction
     */
    void setConnection(Direction d, Connection& c) {
        if(d >= NUM_DIR || d < 0) {
            throw std::string("Index Out of Bounds");
        }

        connections[d] = &c;
    }

    /**
     * Gets the connection in the direction
     * @param d the direction to get a connection in
     * @return the specified connection
     * NOTE: Throws Index Out of Bounds exception if given non-enum specified direction, or Invalid Direction if given an unset direction
     */
    Connection& getConnection(Direction d) const {
        if(d >= NUM_DIR || d < 0) {
            throw std::string("Index Out of Bounds");
        } else if(connections[d] == nullptr) {
            throw std::string("Invalid Direction");
        }

        return *(connections[d]);
    }

    /**
     * Gets the inventory of the given room
     * @return the room's inventory
     */
    Inventory& getInventory() const { return inventory; }

    /**
     * Overloaded << operator that prints all the info about a given room to the provided ostream
     * @param os the ostream to print to
     * @param room the room that info should be printed for
     * @return the ostream with the description text
     */
    friend std::ostream& operator<<(std::ostream& os, const Room& room);

};


#endif //PROJECTCHAONIA_ROOM_H
