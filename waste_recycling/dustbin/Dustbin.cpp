//
// Created by jeannie on 2017.10.20..
//

#include "Dustbin.h"

Dustbin::Dustbin()
        : color("gray") {}

Dustbin::Dustbin(std::string color)
        : color(color) {}

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

void Dustbin::emptyContents() {
    paperContent.clear();
    plasticContent.clear();
    houseWasteContent.clear();
}

void Dustbin::throwOutGarbage(Garbage& waste) {
    houseWasteContent.push_back(waste);
}

void Dustbin::throwOutPaperGarbage(PaperGarbage& waste) {
    if (waste.squeezeState()) {
        paperContent.push_back(waste);
    } else {
        throw DustbinContentError();
    }
}

void Dustbin::throwOutPlasticGarbage(PlasticGarbage& waste) {
    if (waste.cleanState()) {
        plasticContent.push_back(waste);
    } else {
        throw DustbinContentError();
    }
}
