//
// Created by jeannie on 2017.10.20..
//

#include "Dustbin.h"

Dustbin::Dustbin()
        : color("gray"), capacity(100), currentWeight(0), type("Dustbin") {}

Dustbin::Dustbin(std::string color)
        : color(color), capacity(100), currentWeight(0), type("Dustbin") {}

Dustbin::~Dustbin() {}

const std::string &Dustbin::getColor() const {
    return color;
}

unsigned long Dustbin::getPaperGarbageAmount() const {
    return paperContent.size();
}

unsigned long Dustbin::getPlasticGarbageAmount() const {
    return plasticContent.size();
}

unsigned long Dustbin::getHouseWasteAmount() const {
    return houseWasteContent.size();
}

unsigned int Dustbin::getCurrentWeight() const {
    return currentWeight;
}

void Dustbin::emptyContents() {
    paperContent.clear();
    plasticContent.clear();
    houseWasteContent.clear();
    currentWeight = 0;
}

void Dustbin::throwOutGarbage(Garbage& waste) {
    if (isOverflow(waste.getWeight())) throw DustbinIsFull();
    houseWasteContent.push_back(waste);
    addWeight(waste.getWeight());
}

void Dustbin::throwOutPaperGarbage(PaperGarbage& waste) {
    if (isOverflow(waste.getWeight())) throw DustbinIsFull();
    if (!waste.squeezeState()) throw DustbinContentError();
    paperContent.push_back(waste);
    addWeight(waste.getWeight());
}

void Dustbin::throwOutPlasticGarbage(PlasticGarbage& waste) {
    if (isOverflow(waste.getWeight())) throw DustbinIsFull();
    if (!waste.cleanState()) throw DustbinContentError();
    plasticContent.push_back(waste);
    addWeight(waste.getWeight());
}

bool Dustbin::isOverflow(unsigned garbageWeight) {
    return (capacity-currentWeight) < garbageWeight;
}

void Dustbin::addWeight(unsigned garbageWeight) {
    currentWeight += garbageWeight;
}

const std::string &Dustbin::getType() const {
    return type;
}


