//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_METALGARBAGE_HPP
#define WASTE_METALGARBAGE_HPP

#include "Garbage.hpp"

class MetalGarbage : public Garbage {

public:
    MetalGarbage(std::string name)
        : Garbage(name) {}

    ~MetalGarbage() {}
};

#endif //WASTE_METALGARBAGE_HPP
