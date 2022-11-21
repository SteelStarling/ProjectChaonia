//
// Created by thanc on 11/17/22.
//

#include "Room.h"

Room::Room(const std::string name, const std::string description) : Object(name, description), inventory("In the room, there are: ") {

    connections.resize(NUM_DIR); // set to be correct size

    for(int i = NORTH; i < NUM_DIR; i++) {
        connections[i] = nullptr;
    }
}

std::string Room::getConnectionString() const {
    std::string connectionString = ""; // start with empty string to fill

    // Note: endl was being weird, so we're just using \n here

    for(int i = NORTH; i < NUM_DIR; i++) {
        if(connections[i] != NULL) { // only print valid values
            connectionString += connections[i]->getDescription() + "\n";
        }
    }

    return connectionString;
}

std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << room.getName() << std::endl << room.getDescription() << std::endl << room.getItemString() << room.getConnectionString();

    return os;
}

std::string directionToString(Direction d) {
    switch(d) {
        case NORTH:
            return std::string("north");
        case NORTHEAST:
            return std::string("northeast");
        case EAST:
            return std::string("east");
        case SOUTHEAST:
            return std::string("southeast");
        case SOUTH:
            return std::string("south");
        case SOUTHWEST:
            return std::string("southwest");
        case WEST:
            return std::string("west");
        case NORTHWEST:
            return std::string("northwest");
        case UP:
            return std::string("up");
        case DOWN:
            return std::string("down");
        default:
            throw std::string("Index Out of Bounds");
    }
}