//
// Created by jeannie on 2017.10.20..
//

#include "Dustbin9000.h"

Dustbin9000::Dustbin9000(std::string color)
    : Dustbin(color) {
    type ="Dustbin9000";
}

Dustbin9000::Dustbin9000() {
    type ="Dustbin9000";
}

void Dustbin9000::throwOutMetalGarbage(Garbage waste) {
    if (isOverflow(waste.getWeight())) throw DustbinIsFull();
    metalContent.push_back(waste);
    addWeight(waste.getWeight());
}

void Dustbin9000::throwOutBottlecap(BottleCap cap) {
    if (isOverflow(cap.getWeight())) throw DustbinIsFull();
    if (cap.getColor()!="pink") throw BottleCapException();
    pinkBottleCaps.push_back(cap);
    addWeight(cap.getWeight());
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

