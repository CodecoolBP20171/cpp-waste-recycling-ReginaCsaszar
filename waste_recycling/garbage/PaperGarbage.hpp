//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_PAPERGARBAGE_HPP
#define WASTE_PAPERGARBAGE_HPP

#include "Garbage.hpp"

class PaperGarbage : public Garbage {

public:
    explicit PaperGarbage(std::string name)
        : Garbage(name), isSqueezed(false) {}

    ~PaperGarbage() {}

    bool squeezeState() const {
        return isSqueezed;
    }

    void squeeze() {
        isSqueezed = true;
    }

private:
    bool isSqueezed;
};

#endif //WASTE_PAPERGARBAGE_HPP
