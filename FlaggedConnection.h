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
public:
    /**
     * Traverses a connection, returning the corresponding room or throwing an exception if closed
     * @return room across the connection
     * Note: Throws "Connection Closed" exception if flag is false
     */
    Room& traverse() {
        if(!flag) {
            throw string("Connection Closed");
        }

        return traverse();
    }

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
