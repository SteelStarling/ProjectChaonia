//
// Created by Taylor Hancock on 11/19/22.
//

#ifndef PROJECTCHAONIA_INVENTORY_H
#define PROJECTCHAONIA_INVENTORY_H


#include <vector>
#include <string>
#include "Object.h"


class Inventory {
private:
    // TODO: Implement weighted inventory class that limits max weights
    std::string holdDescription; // explains how the objects are held e.g. "you are holding" or "on the floor"
    std::vector<Object*> inventory;
public:

};


#endif //PROJECTCHAONIA_INVENTORY_H
