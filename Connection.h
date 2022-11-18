//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_CONNECTION_H
#define PROJECTCHAONIA_CONNECTION_H

#include "Room.h"

class Connection {
private:
    Room& roomTo;
public:
    /**
     * Creates a new connection to the corresponding room
     * @param roomTo the room to connect to
     */
    Connection(Room& roomTo) : roomTo(roomTo) {}

    /**
     * Traverses a connection, returning the corresponding room
     * @return room across the connection
     */
    virtual Room& traverse() {
        return roomTo;
    }
};


#endif //PROJECTCHAONIA_CONNECTION_H
