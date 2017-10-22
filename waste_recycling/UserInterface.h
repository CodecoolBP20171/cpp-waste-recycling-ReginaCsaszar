//
// Created by jeannie on 2017.10.22..
//

#ifndef DUSTBIN_USERINTERFACE_H
#define DUSTBIN_USERINTERFACE_H

#include <bits/unique_ptr.h>
#include "dustbin/Dustbin9000.h"

class UserInterface {

public:
    UserInterface();
    virtual ~UserInterface();

    void process();

private:

    int selectedMenu;
    std::string givenString;

    void showCarret();
    void showBinOptions();
    void selectColorOrName(std::string type);
    void showGarbageOptions();
    void show9kGarbageOptions();
    void informAboutThrowOut();
    void informAboutFullBin();

    void handlePlastic();
    void handlePaper();
    void handleGarbage();

    void dustbinMenu(Dustbin&);
    void dustbin9kMenu(Dustbin9000&);

    void garbageMenu(Dustbin&);
    void garbage9kMenu(Dustbin9000&);
};


#endif //DUSTBIN_USERINTERFACE_H
