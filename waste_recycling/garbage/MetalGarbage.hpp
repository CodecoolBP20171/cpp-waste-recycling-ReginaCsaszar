//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_METALGARBAGE_HPP
#define WASTE_METALGARBAGE_HPP


#include <iostream>
#include "Garbage.hpp"

class MetalGarbage : public Garbage {

public:
    MetalGarbage(std::string name)
        : Garbage(name) {}

    ~MetalGarbage() {
        std::cout << "You destroyed a MetalGarbage." << std::endl;
    }
};

#endif //WASTE_METALGARBAGE_HPP
