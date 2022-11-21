//
// Created by thanc on 11/17/22.
//

#include "World.h"

// TODO: Add proper FIO checking

World::World(std::string fileName) : fileName(fileName) {
    std::ifstream fin(fileName); // create filestream

    std::string temp; // holds temp values
    std::string name;
    std::string name2;
    std::string name3;
    std::string description;
    std::string descriptionOff;
    std::string descriptionErr;
    std::string flagName;
    std::string direction;

    // reserve space so that flag sizes never change
    flags.reserve(MAX_VALS);
    rooms.reserve(MAX_VALS);
    objects.reserve(MAX_VALS);
    triggers.reserve(MAX_VALS);

    //
    //  FLAGS
    //

    int flagCount = 0;
    fin >> flagCount;
    std::getline(fin, temp); // ignore newline issues

    for(int i = 0; i < flagCount; i++) {
        bool state = false;

        // get flag name and state
        std::getline(fin, name);
        fin >> state;
        std::getline(fin, temp); // ignore newline issues

        // add flag to list and map
        Flag flag(name, state);
        flags.at(i) = flag;
        flagMap[name] = &flags.back();
    }

    //
    //  ROOMS
    //

    int roomCount = 0;
    fin >> roomCount;
    std::getline(fin, temp); // ignore newline issues

    for(int i = 0; i < roomCount; i++) {

        //
        //  ROOM BASIC INFO
        //

        // get room name and description
        std::getline(fin, name);
        std::getline(fin, description);

        // add room to list and map
        Room room(name, description);
        rooms.push_back(room);
        roomMap[name] = &rooms.back();

        //
        //  ROOM CONTENTS
        //

        int objCount = 0;
        fin >> objCount;
        std::getline(fin, temp); // ignore newline issues
        for(int j = 0; j < objCount; j++) {
            // get object name and description
            std::getline(fin, name);
            std::getline(fin, description);

            // add object to list and room
            Object obj(name, description);
            objects.push_back(obj);
            rooms[i].getInventory().addItem(objects.back());
        }

        //
        //  ROOM TRIGGERS
        //

        int trigCount = 0;
        fin >> trigCount;
        std::getline(fin, temp); // ignore newline issues
        for(int j = 0; j < trigCount; j++) {
            // get trigger name, descriptions, and flag
            std::getline(fin, name);
            std::getline(fin, description);
            std::getline(fin, descriptionOff);
            std::getline(fin, name2); // holds flag

            Flag& flag = *flagMap[name2]; // get flag

            // add trigger to list and room
            Trigger trig(flag, name, description, descriptionOff);
            triggers.push_back(trig);
            rooms[i].getInventory().addItem(triggers.back());
        }
    }

    // add player
    this->player = new Player(rooms.at(0));

    // connect rooms
    for(int i = 0; i < roomCount; i++) {

        // get room and connections
        std::getline(fin, name);
        int numConnections = 0;
        fin >> numConnections;
        std::getline(fin, temp); // ignore newline issues

        for(int j = 0; j < numConnections; j++) {

            // get connection type
            char c = 'n';
            fin >> c;
            std::getline(fin, temp); // ignore newline issues

            // get name and description
            std::getline(fin, name2);
            std::getline(fin, description);

            // get flag info if applicable
            if(c == 'f') {
                std::getline(fin, descriptionOff);
                std::getline(fin, descriptionErr);
                std::getline(fin, flagName);
            }

            // get connected room and direction
            std::getline(fin, name3);


            Room& roomTo = *roomMap[name3];
            Room& roomFrom = *roomMap[name];
            std::getline(fin, direction);

            Direction dir;
            if(direction == std::string("N")) {
                dir = NORTH;
            } else if(direction == std::string("NE")) {
                dir = NORTHEAST;
            } else if(direction == std::string("E")) {
                dir = EAST;
            } else if(direction == std::string("SE")) {
                dir = SOUTHEAST;
            } else if(direction == std::string("S")) {
                dir = SOUTH;
            } else if(direction == std::string("SW")) {
                dir = SOUTHWEST;
            } else if(direction == std::string("W")) {
                dir = WEST;
            } else if(direction == std::string("NW")) {
                dir = NORTHWEST;
            } else if(direction == std::string("U")) {
                dir = UP;
            } else if(direction == std::string("D")) {
                dir = DOWN;
            } else { // throws unhandled error if the basic IO is somehow wrong
                throw std::string("ERROR: Invalid direction! " + direction + " is not a valid direction!");
            }

            const std::string& descriptionStore = description;
            if(c == 'f') {
                Flag& flag = *flagMap[flagName];
                FlaggedConnection* connection = new FlaggedConnection(roomTo, name2, descriptionStore, descriptionOff, descriptionErr, flag);
                roomFrom.setConnection(dir, connection);
            } else {
                Connection* connection = new Connection(roomTo, name2, descriptionStore);
                roomFrom.setConnection(dir, connection);
            }

        }
    }
}

void World::play() {
    std::cout << player->getLocation() << std::endl;
    player->traverse(NORTH);
    player->traverse(SOUTH);
    player->traverse(UP);
    player->traverse(DOWN);
    player->traverse(UP);
}