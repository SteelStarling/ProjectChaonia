//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_FLAG_H
#define PROJECTCHAONIA_FLAG_H


#include <string>


// Holds a flag to tell the program what's actually going on
// As a side note, yes, this could be handled by a boolean right now, but I have a sneaking suspicion that that may change down the road, and reimplementing this didn't sound like fun
// TODO: Handle how flags are going to be managed globally
class Flag {
protected:
    std::string name; // name of Flag
    bool state; // binary is just a true or false statement, used for most flags
public:

    /**
     * Creates a flag with a given state
     * @param name the name of the flag
     * @param state the state of the flag to start with, defaults to false
     */
    Flag(std::string name, bool state = false) : name(name), state(state) {}

    /**
     * Returns if the flag is on or off
     * @return the boolean state of the flag
     */
    bool getState() const { return this->state; }

    /**
     * Overload cast to bool to be flag value for obvious use
     * @return the boolean state of the flag
     */
    explicit operator bool() const { return state; }

    /**
     * Sets flag to the provided state
     * @param state the state to set the flag to
     */
    void setState(bool state) { this->state = state; }

    /**
     * Turns the flag on
     */
    void on() { this->state = true; }

    /**
     * Turns the flag off
     */
    void off() { this->state = false; }
};


#endif //PROJECTCHAONIA_FLAG_H
