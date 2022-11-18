//
// Created by thanc on 11/18/22.
//

#ifndef PROJECTCHAONIA_PLAYER_H
#define PROJECTCHAONIA_PLAYER_H


#include "Object.h"
#include "Room.h"

// The actual player
class Player {
private:
    Room& location;
    vector<Object> inventory;
public:
    Player(Room& location) : location(location) {}

    Room& getLocation() const {
        return location;
    }

    void setLocation(Room& location) {
        Player::location = location;
    }

    Object& getInventory(int item) {

    }
};


#endif //PROJECTCHAONIA_PLAYER_H
