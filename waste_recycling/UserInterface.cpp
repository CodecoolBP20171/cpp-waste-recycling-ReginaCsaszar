//
// Created by jeannie on 2017.10.22..
//


#include <iostream>
#include "UserInterface.h"

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void UserInterface::process() {
    bool again = true;
    do {
        std::cout << "\nPlease select a bin:\n\n1 Dustbin\n2 Dustbin9000\n0 Leave";
        readInputInt();
        switch (selectedMenu) {
            case 1 : {
                readInputString("color");
                bin.reset (new Dustbin(givenString));
                dustbinMenu();
                break;
            }
            case 2 : {
                readInputString("color");
                bin.reset (new Dustbin9000(givenString));
                dustbinMenu();
                break;
            }
            case 0 : {
                again = false;
            }
        }
    } while (again);
}

inline void UserInterface::showCarret() {
    std::cout << "\n\n>>";
}
inline void UserInterface::readInputString(std::string type) {
    std::cout << "\nPlease specify a " << type << ":";
    showCarret();
    std::cin >> givenString;
}
inline void UserInterface::readInputInt() {
    showCarret();
    std::cin >> selectedMenu;
}
inline void UserInterface::showBinOptions() {
    std::cout <<"\nWhat do you want to do?\n\n"
            "1 Throw out some garbage\n"
            "2 Empty bin\n"
            "0 Leave";
}
inline void UserInterface::showGarbageOptions() {
    std::cout <<"\nPlease select a garbage:\n\n1 Housewaste\n2 Plastic\n3 Paper";
    if (bin->getType() == "Dustbin9000") {
        std::cout <<"\n4 Metal\n5 Bottle cup";
    }
    std::cout << "\n0 Leave";
}

void UserInterface::dustbinMenu() {
    bool again = true;

    do {
        showBinOptions();
        readInputInt();
        switch (selectedMenu) {
            case 1 : {
                garbageMenu();
                break;
            }
            case 2 : {
                bin->emptyContents();
                std::cout <<"\nDustbin emptied.\n";
                break;
            }
            case 0 : {
                again = false;
            }
        }
    } while(again);
}

void UserInterface::garbageMenu(){ // TODO split&refactor
    bool again = true;
    do {
        showGarbageOptions();
        readInputInt();

        switch (selectedMenu) {
            case 1 : {
                readInputString("name");
                Garbage waste = Garbage(givenString);
                do {
                    std::cout << "\nWhat do you do with your garbage?\n\n1 Throw out\n0 Leave";
                    readInputInt();
                    if (selectedMenu == 1) {
                        try {
                            bin->throwOutGarbage(waste);
                            std::cout << "\nGarbage throwed out.";
                            selectedMenu = 0;
                        } catch (DustbinIsFull&) {
                            std::cout << "\nDustbin is full.";
                        }
                    }
                } while (selectedMenu != 0);
                break;
            }
            case 2 : {
                readInputString("name");
                PlasticGarbage waste = PlasticGarbage(givenString);
                do {
                    std::cout << "\nWhat do you do with your plastic?\n\n1 Throw out\n2 Wash out\n0 Leave";
                    readInputInt();
                    if (selectedMenu == 1) {
                        try {
                            bin->throwOutPlasticGarbage(waste);
                            std::cout << "\nGarbage throwed out.";
                            selectedMenu = 0;
                        } catch (DustbinContentError&) {
                            std::cout << "\nYou can throw out only clean plastic garbage!";
                        } catch (DustbinIsFull&) {
                            std::cout << "\nDustbin is full.";
                        }
                    } else if (selectedMenu == 2) {
                        if (waste.cleanState()) {
                            std::cout << waste.getName()
                                      << " is clean.";
                        } else {
                            waste.clean();
                            std::cout << waste.getName()
                                      << " cleaned.";
                        }
                    }
                } while (selectedMenu != 0);
                break;
            }
            case 3 : {
                readInputString("name");
                PaperGarbage waste = PaperGarbage(givenString);
                do {
                    std::cout << "\nWhat do you do with your paper?\n\n1 Throw out\n2 Squeeze\n0 Leave";
                    readInputInt();
                    if (selectedMenu == 1) {
                        try {
                            bin->throwOutPaperGarbage(waste);
                            std::cout << "\nGarbage throwed out.";
                            selectedMenu = 0;
                        } catch (DustbinContentError&) {
                            std::cout << "\nYou can throw out only squeezed paper!";
                        } catch (DustbinIsFull&) {
                            std::cout << "\nDustbin is full.";
                        }
                    } else if (selectedMenu == 2) {
                        if (waste.squeezeState()) {
                            std::cout << waste.getName()
                                      << " already squeezed.";
                        } else {
                            waste.squeeze();
                            std::cout << waste.getName()
                                      << " squeezed.";
                        }
                    }
                } while (selectedMenu != 0);
                break;
            }
            case 4 : {
                if  (bin->getType() == "Dustbin9000") {
                    readInputString("name");
                    MetalGarbage waste = MetalGarbage(givenString);
                    do {
                        std::cout << "\nWhat do you do with your garbage?\n\n1 Throw out\n0 Leave";
                        readInputInt();
                        if (selectedMenu == 1) {
                            try {
                                static_cast<Dustbin9000*>(bin.get())->throwOutMetalGarbage(waste);
                                std::cout << "\nGarbage throwed out.";
                                selectedMenu = 0;
                            } catch (DustbinIsFull&) {
                                std::cout << "\nDustbin is full.";
                            }
                        }
                    } while (selectedMenu != 0);
                }
                break;
            }
            case 5 : {
                if  (bin->getType() == "Dustbin9000") {
                    readInputString("color");
                    BottleCap waste = BottleCap(givenString);
                    do {
                        std::cout << "\nWhat do you do with your garbage?\n\n1 Throw out\n0 Leave";
                        readInputInt();
                        if (selectedMenu == 1) {
                            try {
                                static_cast<Dustbin9000*>(bin.get())->throwOutBottlecap(waste);
                                std::cout << "\nGarbage throwed out.";
                                selectedMenu = 0;
                            } catch (BottleCapException &) {
                                std::cout << "\nYou can throw out only pink bottlecup!";
                            } catch (DustbinIsFull &) {
                                std::cout << "\nDustbin is full.";
                            }
                        }
                    } while (selectedMenu != 0);
                }
                break;
            }
            case 0 : {
                again = false;
            }
        }
    } while (again);
}
