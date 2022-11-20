//
// Created by thanc on 11/17/22.
//

#include "Room.h"

Room::Room(std::string name, std::string description) : Object(name, description) {
    for(int i = 0; i < NUM_DIR; i++) {
        connections[i] = nullptr;
    }
}

std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << room.getName() << std::endl << room.getDescription() << std::endl
       << room.getInventory().getItemString() << std::endl;

    return os;
}