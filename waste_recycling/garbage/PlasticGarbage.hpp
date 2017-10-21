//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_PLASTICGARBAGE_HPP
#define WASTE_PLASTICGARBAGE_HPP

#include "Garbage.hpp"

class PlasticGarbage : public Garbage {

public:
    explicit PlasticGarbage(std::string name)
        : Garbage(name), isClean(false) {}

    ~PlasticGarbage() {
        std::cout << "You destroyed a PlasticGarbage." << std::endl;
    }

    bool cleanState() const {
        return isClean;
    }

    void clean() {
        isClean = true;
        std::cout << "You washed a PlasticGarbage." << std::endl;
    }

private:
    bool isClean;
};

#endif //WASTE_PLASTICGARBAGE_HPP
