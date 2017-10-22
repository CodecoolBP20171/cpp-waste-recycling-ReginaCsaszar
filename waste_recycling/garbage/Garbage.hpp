//
// Created by jeannie on 2017.10.20..
//
#ifndef WASTE_GARBAGE_HPP
#define WASTE_GARBAGE_HPP

#include <string>

class Garbage {

public:
    Garbage(std::string name, unsigned weight)
        : name(name), weight(weight){}

    explicit Garbage(std::string name)
            : name(name), weight(7){}

    virtual ~Garbage() {}

    const std::string& getName() const {
        return name;
    }

    const unsigned getWeight() const {
        return weight;
    }

protected:
    const std::string name;
    const unsigned weight;
};

#endif //WASTE_METALGARBAGE_HPP