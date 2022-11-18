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
    string getItemString() const;

    /**
     * Prints the items in the room
     */
    void printItems() const { cout << getItemString(); }

    /**
     * Overloaded << operator that prints all the info about a given room to the provided ostream
     * @param os the ostream to print to
     * @param room the room that info should be printed for
     * @return the ostream with the description text
     */
    friend std::ostream& operator<<(std::ostream& os, const Room& room);

};


#endif //PROJECTCHAONIA_ROOM_H
