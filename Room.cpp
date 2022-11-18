//
// Created by thanc on 11/17/22.
//

#include "Room.h"

std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << room.getName() << std::endl << room.getDescription() << std::endl;

    for(int i = 0; i < items.size())

    return os;
}