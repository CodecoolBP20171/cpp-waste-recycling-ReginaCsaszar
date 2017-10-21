//
// Created by jeannie on 2017.10.20..
//

#include <iostream>
#include "Dustbin9000.h"

Dustbin9000::Dustbin9000(std::string color) {}

Dustbin9000::Dustbin9000() {}

void Dustbin9000::throwOutMetalGarbage(Garbage item) {
    metalContent.push_back(item);
    std::cout << "You dropped MetalGarbage into the Dustbin9000." << std::endl;
}

void Dustbin9000::throwOutBottlecap(BottleCap cap) {
    if (cap.getColor()=="pink") {
        pinkBottleCaps.push_back(cap);
        std::cout << "You dropped a pink BottleCap into the Dustbin9000." << std::endl;
    } else {
        std::cout << "The Dustbin900 accept pink BootleCap only."
                  "It fires back the cap to your face."
                  <<  std::endl;
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

Dustbin9000::~Dustbin9000() {
    std::cout << "You disabled a Dustbin9000 upgrade. ";
}

