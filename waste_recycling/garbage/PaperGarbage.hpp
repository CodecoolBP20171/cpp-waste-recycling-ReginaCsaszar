//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_PAPERGARBAGE_HPP
#define WASTE_PAPERGARBAGE_HPP

#include <string>
#include "Garbage.hpp"


class PaperGarbage : public Garbage {

public:
    explicit PaperGarbage(std::string name)
        : Garbage(name), isSqueezed(false) {}

    ~PaperGarbage() {
        std::cout << "You destroyed a PaperGarbage." << std::endl;
    }

    bool squeezeState() const {
        return isSqueezed;
    }

    void squeeze() {
        isSqueezed = true;
        std::cout << "You squeeze a PlasticGarbage." << std::endl;
    }

private:
    bool isSqueezed;
};


#endif //WASTE_PAPERGARBAGE_HPP
