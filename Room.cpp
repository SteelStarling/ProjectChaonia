//
// Created by thanc on 11/17/22.
//

#include "Room.h"

Room::Room(const std::string name, const std::string description) : Object(name, description), inventory("In the room, there are: ") {
    connections.resize(NUM_DIR); // set to be correct size

    for(int i = 0; i < NUM_DIR; i++) {
        connections[i] = nullptr;
    }
}

std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << room.getName() << std::endl;
    os << room.getDescription() << std::endl;
    os << room.getItemString() << std::endl;

    return os;
}