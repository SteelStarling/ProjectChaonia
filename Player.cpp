//
// Created by thanc on 11/18/22.
//

#include "Player.h"

bool Player::traverse(Direction d) {
    Room& r = location;

    try {
        r = location.getConnection(d).traverse(); // try traversing
    } catch(std::string errMsg) {
        if(errMsg == std::string("Index Out of Bounds")) { // handle out of bounds
            std::cout << "...whatever direction you just input isn't...real...sadly, this game does not allow you to "
                      << "move into the 4th dimension, so please try again." << std::endl;
        } else if(errMsg == std::string("Invalid Direction")) { // handle directions that are empty
            std::cout << "The direction you input doesn't lead to a passageway." << std::endl
                      << "You seem to remember being told in your youth to never leave the trail, presumably this must "
                      << "be similar, please try again." << std::endl;
        }

        return false;
    }

    location = r; // update location
}

void Player::pickUp(int item) {
    Object* o = nullptr;

    try {
        o = &location.getInventory().removeItem(item);
    } catch(std::string errMsg) {
        std::cout << "There is no matching item, please try a different command." << std::endl;

        return; // stop running
    }

    // add only if valid
    if(o != nullptr) {
        inventory.addItem(*o);
    }
}

void Player::setDown(int item) {
    Object* o = nullptr;

    try {
        o = &inventory.removeItem(item);
    } catch(std::string errMsg) {
        std::cout << "There is no matching item, please try a different command." << std::endl;

        return; // stop running
    }

    // add only if valid
    if(o != nullptr) {
        location.getInventory().addItem(*o);
    }
}