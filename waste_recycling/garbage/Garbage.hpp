//
// Created by jeannie on 2017.10.20..
//
#ifndef WASTE_GARBAGE_HPP
#define WASTE_GARBAGE_HPP

#include <string>

class Garbage {

public:
    explicit Garbage(std::string name)
        : name(name){}

    virtual ~Garbage() {}

    const std::string& getName() const {
        return name;
    }

protected:
    const std::string name;
};

#endif //WASTE_METALGARBAGE_HPP