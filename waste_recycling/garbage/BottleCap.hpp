//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_BOTTLECAP_HPP
#define WASTE_BOTTLECAP_HPP

#include "Garbage.hpp"

class BottleCap : public Garbage {

public:
    explicit BottleCap(std::string col)
        : Garbage("bottlecap"), color(col) {}

    explicit BottleCap()
        : Garbage("bottlecap"), color("pink") {}

    ~BottleCap() {}

    const std::string &getColor() const {
        return color;
    }

private:
    const std::string color;
};

#endif //WASTE_BOTTLECAP_HPP
