//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_WORLD_H
#define PROJECTCHAONIA_WORLD_H


#include "Room.h"
#include "Object.h"

#include <unordered_map>


class World {
private:
    std::unordered_map<std::string, Room> rooms; // holds master copy of every room (where everything points to)

};


#endif //PROJECTCHAONIA_WORLD_H
