
//
// Created by Taylor Hancock on 11/20/22.
//

#ifndef PROJECTCHAONIA_TRIGGER_H
#define PROJECTCHAONIA_TRIGGER_H


#include "Object.h"
#include "Flag.h"

#include <string>

class Trigger : public Object {
private:
    Flag* flag;
    std::string offDescription; // holds description of trigger when flag is off
public:
    /**
     * Creates a new trigger
     * @param flag the flag to use for the trigger
     * @param name the name of the trigger
     * @param onDescription a description of the trigger when it is on
     * @param offDescription a description of the trigger when it is off
     */
    Trigger(Flag& flag, std::string name, std::string onDescription, std::string offDescription) : Object(name, onDescription) { this->flag = &flag; }

    /**
     * Gets the Trigger's description, getting the description corresponding to the flag
     * @return the correct description for the trigger based on the flag
     */
    std::string getDescription() { return flag ? getDescription() : offDescription; }

    /**
     * Gets the trigger's flag
     * @return the flag held by the Trigger
     */
    Flag& getFlag() { return *flag; }
};


#endif //PROJECTCHAONIA_TRIGGER_H
