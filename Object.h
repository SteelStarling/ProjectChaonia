//
// Created by thanc on 11/17/22.
//

#ifndef PROJECTCHAONIA_OBJECT_H
#define PROJECTCHAONIA_OBJECT_H


#include <string>
#include <iostream>
#include <vector>

class Object {
protected:
    std::string name;           // holds the object's name
    std::string description;    // holds the object's description
public:

    //TODO: Solve a vs an programmatically, but that's a problem for future Taylor

    /**
     * Creates a new object with a given name and description
     * @param name the name of the object
     * @param description a description of the object
     */
    Object(const std::string& name, const std::string& description);

    /**
     * Creates a new object with a given name
     * @param name the name of the object
     */
    Object(const std::string& name);

    /**
     * Returns the object's name
     * @return the name of the object
     */
    std::string getName() const { return name; }

    /**
     * Returns the object's description
     * @return the description of the object
     */
    virtual std::string getDescription() const { return description; }

    /**
     * Prints the name of the object
     */
    void printName() const { std::cout << name << std::endl; }

    /**
     * Prints the description of the object
     */
    void printDescription() const { std::cout << description << std::endl; }

    /**
     * Overloaded << operator that prints all the info about a given object to the provided ostream
     * @param os the ostream to print to
     * @param obj the object that info should be printed for
     * @return the ostream with the description text
     */
    friend std::ostream& operator<<(std::ostream& os, const Object& obj);

};


#endif //PROJECTCHAONIA_OBJECT_H
