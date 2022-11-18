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
};


#endif //PROJECTCHAONIA_ROOM_H
