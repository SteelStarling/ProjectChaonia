//
// Created by thanc on 11/17/22.
//

#include "Room.h"

std::string Room::getItemString() const {
    std::string itemString = ""; // start with empty string to fill

    // Note: endl was being weird, so we're just using \n here

    if(items.size() > 0) { // print nothing if there are no items
        itemString += "In the room, there ";
        if (items.size() == 1) { // handle singular and plural
            itemString += "is:\n";
        } else {
            itemString += "are:\n";
        }

        // print each with numbers
        for (int i = 0; i < items.size(); i++) {
            itemString += "    " + to_string(i) + ". " + items.at(i).getName() + "\n";
        }
    }

    return itemString;
}

std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << room.getName() << std::endl << room.getDescription() << std::endl << room.getItemString() << std::endl;

    return os;
}