//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_ROOM_H
#define PROJECTCHAONIA_ROOM_H


#include "Object.h"

class Room : public Object {
private:
    vector<Object> items; // holds all items present in the room

public:
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
        DOWN
    };

    /**
     * Gets a string holding the names of every item in the room
     * @return a string holding every item in the room sepearated by a newline
     */
    string getItemString() {
        std::string itemString = ""; // start with empty string to fill
        for(int i = 0; i < items.size(); i++) {
            itemString += items.at(i).getName() + "\n"; // Note: endl was being weird here, so we're using the normal way instead
        }
        return itemString;
    }

    void printItems() {
        if(items.size() > 0) { // print nothing if there are no items
            cout << "In the room, there ";
            if(items.size() == 1) { // handle singular and plural
                cout << "is:";
            } else {
                cout << "are:";
            }
            cout << getItemString();
        }
    }

    /**
     * Overloaded << operator that prints all the info about a given room to the provided ostream
     * @param os the ostream to print to
     * @param room the room that info should be printed for
     * @return the ostream with the description text
     */
    friend std::ostream& operator<<(std::ostream& os, const Room& room);
};


#endif //PROJECTCHAONIA_ROOM_H
