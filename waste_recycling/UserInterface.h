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
    ~UserInterface();

    void process();

private:

    std::unique_ptr<Dustbin> bin;

    int selectedMenu;
    std::string givenString;

    void showCarret();
    void showBinOptions();
    void showGarbageOptions();
    void readInputString(std::string type);
    void readInputInt();

    void dustbinMenu();
    void garbageMenu();

};


#endif //DUSTBIN_USERINTERFACE_H
