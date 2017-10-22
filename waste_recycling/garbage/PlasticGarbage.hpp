//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_PLASTICGARBAGE_HPP
#define WASTE_PLASTICGARBAGE_HPP

#include "Garbage.hpp"

class PlasticGarbage : public Garbage {

public:
    explicit PlasticGarbage(std::string name)
        : Garbage(name, 10), isClean(false) {}

    ~PlasticGarbage() {}

    bool cleanState() const {
        return isClean;
    }

    void clean() {
        isClean = true;
    }

private:
    bool isClean;
};

#endif //WASTE_PLASTICGARBAGE_HPP
