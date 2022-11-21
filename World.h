//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_WORLD_H
#define PROJECTCHAONIA_WORLD_H

#include "Player.h"
#include "FlaggedConnection.h"
#include "Trigger.h"
#include "Flag.h"
#include "Connection.h"
#include "Room.h"
#include "Object.h"


#include <string>
#include <unordered_map>
#include <fstream>

class World {
protected:
    const std::string fileName;

    std::string fileText; // holds entire text of worldFile.txt

    // maps connecting strings and rooms
    std::unordered_map<std::string, Room*> roomMap;
    std::unordered_map<std::string, Flag*> flagMap;

    // vectors hold master copy of every object
    std::vector<Flag> flags;
    std::vector<Room> rooms;
    std::vector<Object> objects;
    std::vector<Trigger> triggers;

    // holds player
    Player* player;

public:

    /**
     * Creates a world based on the fileName
     */
    World(std::string fileName = std::string("worldFile.txt"));

    /**
     * Plays the world
     */
    void play();
};


#endif //PROJECTCHAONIA_WORLD_H
