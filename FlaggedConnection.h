//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_FLAGGEDCONNECTION_H
#define PROJECTCHAONIA_FLAGGEDCONNECTION_H


#include "Connection.h"
#include "Flag.h"

// A connection with a flag that determines if the connection works
class FlaggedConnection : public Connection {
protected:
    Flag* flag;

    // messages depending on if the connection is open or closed (normal description is open)
    std::string closedMsg;

    // message to print if someone tries to walk through a closed door
    std::string errorMsg;
public:
    /**
     * Creates a new connection to the corresponding room
     * @param roomTo the room to connect to
     * @param name the name of the connection
     * @param description a description of the connection when open
     * @param closedMsg a description of the connection when closed
     * @param errorMsg a description of why you can't use the closed connection
     * @param flag the flag the connection uses to control if it's open or closed
     */
    FlaggedConnection(Room& roomTo, std::string name, std::string description, std::string closedMsg, std::string errorMsg, Flag& flag) : Connection(roomTo, name, description), closedMsg(closedMsg), errorMsg(errorMsg) { this->flag = &flag; }

    /**
     * Traverses a connection, returning the corresponding room or throwing an exception if closed
     * @return room across the connection
     * Note: Throws "Connection Closed" exception if flag is false, and prints a message pointing it out
     */
    Room& traverse() {
        if(!(*flag)) {
            std::cout << errorMsg << std::endl;
            throw std::string("Connection Closed");
        }

        return traverse();
    }

    /**
     * Returns the FlaggedConnection's description depending on the flag state
     * @return the correct description of the FlaggedConnection
     */
    std::string getDescription() const { return (*flag) ? getDescription() : closedMsg; }

    // TODO: Check if this way of handling flags is smart, or if it should really all be handled with FlaggedConnection imports of Flag functions

    /**
     * Get the flag value to operate on
     * @return
     */
    Flag& getFlag() {
        return *flag;
    }
};


#endif //PROJECTCHAONIA_FLAGGEDCONNECTION_H
