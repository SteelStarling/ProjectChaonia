//
// Created by thanc on 11/17/22.
//

#include "Object.h"


Object::Object(const std::string name, const std::string description) :name(name), description(description) {}

Object::Object(const std::string name) : name(name), description(((std::string)"It is a completely unremarkable ").append(name)) {}

std::ostream& operator<<(std::ostream& os, const Object& obj) {
    os << obj.getName() << std::endl << obj.getDescription() << std::endl;

    return os;
}
