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
#include <array>
#include <fstream>
#include <iostream>

#define MAX_VALS 500

class World {
protected:
    const std::string fileName;

    // holds player
    Player* player;

public:

    // FUN VECTOR FACT! EVERY TIME YOU CHANGE THE SIZE OF A VECTOR, IT CHANGES THE POINTERS TO EVERYTHING IN THE VECTOR. THIS FACT TOOK ME OVER 2 HOURS OF DEBUGGING TO FIGURE OUT. YAYYYY

    // maps connecting strings and rooms
    std::unordered_map<std::string, Room*> roomMap;
    std::unordered_map<std::string, Flag*> flagMap;

    // arrays hold master copy of every object
    std::vector<Flag> flags;
    std::vector<Room> rooms;
    std::vector<Object> objects;
    std::vector<Trigger> triggers;

    /**
     * Creates a world based on the fileName
     */
    World(std::string fileName = "D:\\ERAU\\Sophomore Year\\CS225\\ProjectChaonia\\worldFile.txt");

    /**
     * Plays the world
     */
    void play();
};


#endif //PROJECTCHAONIA_WORLD_H
