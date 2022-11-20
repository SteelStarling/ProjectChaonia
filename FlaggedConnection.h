//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_FLAGGEDCONNECTION_H
#define PROJECTCHAONIA_FLAGGEDCONNECTION_H


#include "Connection.h"
#include "Flag.h"

// A connection with a flag that determines if the connection works
class FlaggedConnection : public Connection {
private:
    Flag& flag;

    // messages depending on if the connection is open or closed
    std::string openMsg;
    std::string closedMsg;

    // message to print if someone tries to walk through a closed door
    std::string errorMessage;
public:
    /**
     * Traverses a connection, returning the corresponding room or throwing an exception if closed
     * @return room across the connection
     * Note: Throws "Connection Closed" exception if flag is false, and prints a message pointing it out
     */
    Room& traverse() {
        if(!flag) {
            std::cout << errorMessage << std::endl;
            throw std::string("Connection Closed");
        }

        return traverse();
    }

    /**
     * Returns the FlaggedConnection's description depending on the flag state
     * @return the correct description of the FlaggedConnection
     */
    std::string getDescription() const { return flag ? openMsg : closedMsg; }

    // TODO: Check if this way of handling flags is smart, or if it should really all be handled with FlaggedConnection imports of Flag functions

    /**
     * Get the flag value to operate on
     * @return
     */
    Flag& getFlag() {
        return flag;
    }
};


#endif //PROJECTCHAONIA_FLAGGEDCONNECTION_H
