//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_DUSTBIN_H
#define WASTE_DUSTBIN_H

#include <string>
#include <vector>

#include "../garbage/Garbage.hpp"
#include "../garbage/PaperGarbage.hpp"
#include "../garbage/PlasticGarbage.hpp"

#include "DustbinContentError.hpp"

class Dustbin {

public:
    Dustbin();
    explicit Dustbin(std::string);

    void throwOutGarbage(Garbage&);
    void throwOutPaperGarbage(PaperGarbage&);
    void throwOutPlasticGarbage(PlasticGarbage&);

    virtual void emptyContents();

    const std::string &getColor() const;
    unsigned long getPaperGarbageAmount() const;
    unsigned long getPlasticGarbageAmount() const;
    unsigned long getHouseWasteAmount() const;

    virtual ~Dustbin();

protected:
    const std::string color;

private:
    std::vector<PaperGarbage> paperContent;
    std::vector<PlasticGarbage> plasticContent;
    std::vector<Garbage> houseWasteContent;

};


#endif //WASTE_DUSTBIN_H
