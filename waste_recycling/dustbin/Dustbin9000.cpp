//
// Created by jeannie on 2017.10.20..
//

#include "Dustbin9000.h"

Dustbin9000::Dustbin9000(std::string color)
    : Dustbin(color) {}

Dustbin9000::Dustbin9000() {}

void Dustbin9000::throwOutMetalGarbage(Garbage item) {
    metalContent.push_back(item);
}

void Dustbin9000::throwOutBottlecap(BottleCap cap) {
    if (cap.getColor()=="pink") {
        pinkBottleCaps.push_back(cap);
    } else {
        throw BottleCapException();
    }
}

void Dustbin9000::emptyContents() {
    metalContent.clear();
    pinkBottleCaps.clear();
    Dustbin::emptyContents();
}

unsigned long Dustbin9000::getMetalGarbageAmount() const {
    return metalContent.size();
}

unsigned long Dustbin9000::getBottlecapAmount() const {
    return pinkBottleCaps.size();
}

Dustbin9000::~Dustbin9000() {}

