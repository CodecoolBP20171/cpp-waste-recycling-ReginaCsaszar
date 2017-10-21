//
// Created by jeannie on 2017.10.20..
//

#include <iostream>
#include "Dustbin.h"

Dustbin::Dustbin()
        : color("gray") {}

Dustbin::Dustbin(std::string color)
        : color(color) {}

Dustbin::~Dustbin() {
    std::cout << "You destroyed a Dustbin." << std::endl;
}

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
    std::cout << "You emptied the Dustbin." << std::endl;
}

void Dustbin::throwOutGarbage(Garbage& waste) {
    houseWasteContent.push_back(waste);
    std::cout << "You dropped Garbage into the Dustbin." << std::endl;
}

void Dustbin::throwOutPaperGarbage(PaperGarbage& waste) {
    if (waste.squeezeState()) {
        paperContent.push_back(waste);
        std::cout << "You dropped PaperGarbage into the Dustbin." << std::endl;
    } else {
        std::cout << "The Dustbin accept squeezed PaperGarbage only." <<  std::endl;
        throw DustbinContentError();
    }
}

void Dustbin::throwOutPlasticGarbage(PlasticGarbage& waste) {
    if (waste.cleanState()) {
        plasticContent.push_back(waste);
        std::cout << "You dropped PlasticGarbage into the Dustbin." << std::endl;
    } else {
        std::cout << "The Dustbin accept clean PlasticGarbage only." <<  std::endl;
        throw DustbinContentError();
    }
}
