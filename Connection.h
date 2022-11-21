//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_CONNECTION_H
#define PROJECTCHAONIA_CONNECTION_H

#include "Room.h"
#include "Object.h"

class Room; // forward declaration

class Connection : public Object {
protected:
    Room& roomTo;
public:
    /**
     * Creates a new connection to the corresponding room
     * @param roomTo the room to connect to
     * @param name the name of the connection
     * @param description a description of the connection
     */
    Connection(Room& roomTo, std::string name, std::string description) : roomTo(roomTo), Object(name, description) {}

    /**
     * Creates a new connection to the corresponding room
     * @param roomTo the room to connect to
     * @param name the name of the connection
     */
    Connection(Room& roomTo, std::string name) : roomTo(roomTo), Object(name, "A passage leads away") {}

    /**
     * Traverses a connection, returning the corresponding room
     * @return room across the connection
     */
    virtual Room& traverse() {
        return roomTo;
    }
};


#endif //PROJECTCHAONIA_CONNECTION_H
