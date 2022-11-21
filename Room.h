//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_ROOM_H
#define PROJECTCHAONIA_ROOM_H


#include "Object.h"
#include "Connection.h"
#include "Inventory.h"

#include <string>
#include <vector>

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

class Connection; // forward declaration

class Room : public Object {
protected:
    Inventory inventory; // holds all items present in the room
    std::vector<Connection*> connections; // holds all connections

public:

    /**
     * Creates a new room with no items or connections
     * @param name the name of the room
     * @param description the description of the room
     */
    Room(const std::string name, const std::string description);

    Room(const Room& original) : Object(original.name, original.description), inventory(original.inventory), connections(original.connections) {}

    //NOTE: We only handle pointers here, because we want to ensure that objects cannot be destroyed without good reason - All objects are stored in the Object Master List held by the game itself.

    /**
     * Sets the connection in the direction
     * @param d the direction to set the connection in
     * @param c pointer to the connection to set
     * NOTE: Throws Index Out of Bounds exception if given non-enum specified direction
     */
    void setConnection(Direction d, Connection* c) {
        if(d >= NUM_DIR || d < 0) {
            throw std::string("Index Out of Bounds");
        }

        connections[d] = c;
    }

    /**
     * Gets the connection in the direction
     * @param d the direction to get a connection in
     * @return the specified connection
     * NOTE: Throws Index Out of Bounds exception if given non-enum specified direction, or Invalid Direction if given an unset direction
     */
    Connection& getConnection(Direction d) {
        if(d >= NUM_DIR || d < 0) {
            throw std::string("Index Out of Bounds");
        } else if(connections.at(d) == nullptr) {
            throw std::string("Invalid Direction");
        }

        return *(connections.at(d));
    }

    /**
     * Gets the connection string of the given room
     * @return the room's connections string
     */
    std::string getConnectionString() const;

    /**
     * Gets the inventory of the given room
     * @return the room's inventory
     */
    Inventory& getInventory() { return inventory; }

    /**
     * Gets the item string of the inventory in the given room
     * @return the room's item string
     */
    std::string getItemString() const { return inventory.getItemString(); }

    /**
     * Overloaded << operator that prints all the info about a given room to the provided ostream
     * @param os the ostream to print to
     * @param room the room that info should be printed for
     * @return the ostream with the description text
     */
    friend std::ostream& operator<<(std::ostream& os, const Room& room);

};

/**
 * Converts a direction to a string
 * @param d the direction to convert
 * @return a string corresponding to the direction
 * NOTE: Throws "Index Out of Bounds" exception if given invalid direction
 */
std::string directionToString(Direction d);


#endif //PROJECTCHAONIA_ROOM_H
