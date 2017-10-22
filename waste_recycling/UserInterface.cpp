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
        showCarret();
        std::cin >> selectedMenu;
        switch (selectedMenu) {
            case 1 : {
                selectColorOrName("color");
                Dustbin bin = Dustbin(givenString);
                dustbinMenu(bin);
                break;
            }
            case 2 : {
                selectColorOrName("color");
                Dustbin9000 bin9k = Dustbin9000(givenString);
                dustbin9kMenu(bin9k);
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
inline void UserInterface::showBinOptions() {
    std::cout <<"\nWhat do you want to do?\n\n"
            "1 Throw out some garbage\n"
            "2 Empty bin\n"
            "0 Leave";
}
inline void UserInterface::selectColorOrName(std::string type) {
    std::cout << "\nPlease specify a " << type << ":";
    showCarret();
    std::cin >> givenString;
}
inline void UserInterface::informAboutFullBin() {
    std::cout << "\nDustbin is full.";
}
inline void UserInterface::informAboutThrowOut() {
    std::cout << "\nGarbage throwed out.";
}

void UserInterface::handleGarbage(){
    std::cout << "\nWhat do you do with your garbage?\n\n1 Throw out\n0 Leave";
    showCarret();
    std::cin >> selectedMenu;
}
void UserInterface::handlePaper() {
    std::cout << "\nWhat do you do with your paper?\n\n1 Throw out\n2 Squeeze\n0 Leave";
    showCarret();
    std::cin >> selectedMenu;
}
void UserInterface::handlePlastic() {
    std::cout << "\nWhat do you do with your plastic?\n\n1 Throw out\n2 Wash out\n0 Leave";
    showCarret();
    std::cin >> selectedMenu;
}

inline void UserInterface::showGarbageOptions() {
    std::cout <<"\nPlease select a garbage:\n\n1 Housewaste\n2 Plastic\n3 Paper\n0 Leave";
}
inline void UserInterface::show9kGarbageOptions() {
    std::cout <<"\nPlease select a garbage:\n\n"
            "1 Housewaste\n"
            "2 Plastic\n"
            "3 Paper\n"
            "4 Metal\n"
            "5 Bottle cup\n"
            "0 Leave";
}

void UserInterface::dustbinMenu(Dustbin& bin) {
    bool again = true;
    do {
        showBinOptions();
        showCarret();
        std::cin >> selectedMenu;
        switch (selectedMenu) {
            case 1 : {
                garbageMenu(bin);
                break;
            }
            case 2 : {
                bin.emptyContents();
                std::cout <<"\nDustbin emptied.\n";
                break;
            }
            case 0 : {
                again = false;
            }
        }
    } while(again);
}

void UserInterface::dustbin9kMenu(Dustbin9000& bin){
    bool again = true;
    do {
        showBinOptions();
        showCarret();
        std::cin >> selectedMenu;
        switch (selectedMenu) {
            case 1 : {
                garbage9kMenu(bin);
                break;
            }
            case 2 : {
                bin.emptyContents();
                std::cout <<"\nDustbin emptied.\n";
                break;
            }
            case 0 : {
                again = false;
            }
        }
    } while(again);
}

void UserInterface::garbage9kMenu(Dustbin9000& bin){
    bool again = true;
    do {
        show9kGarbageOptions();
        showCarret();
        std::cin >> selectedMenu;

        switch (selectedMenu) {
            case 1 : {
                selectColorOrName("name");
                Garbage waste = Garbage(givenString);
                do {
                    handleGarbage();
                    if (selectedMenu == 1) {
                        try {
                            bin.throwOutGarbage(waste);
                            informAboutThrowOut();
                        } catch (DustbinIsFull&) {
                            informAboutFullBin();
                        }
                    }
                } while (selectedMenu != 0);
                break;
            }
            case 2 : {
                selectColorOrName("name");
                PlasticGarbage waste = PlasticGarbage(givenString);
                do {
                    handlePlastic();
                    if (selectedMenu == 1) {
                        try {
                            bin.throwOutGarbage(waste);
                            informAboutThrowOut();
                        } catch (DustbinContentError&) {
                            std::cout << "\nYou can throw out only clean plastic garbage!";
                        } catch (DustbinIsFull&) {
                            informAboutFullBin();
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
                selectColorOrName("name");
                PaperGarbage waste = PaperGarbage(givenString);
                do {
                    handlePaper();
                    if (selectedMenu == 1) {
                        try {
                            bin.throwOutGarbage(waste);
                            informAboutThrowOut();
                        } catch (DustbinContentError&) {
                            std::cout << "\nYou can throw out only squeezed paper!";
                        } catch (DustbinIsFull&) {
                            informAboutFullBin();
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
                selectColorOrName("name");
                MetalGarbage waste = MetalGarbage(givenString);
                do {
                    handleGarbage();
                    if (selectedMenu == 1) {
                        try {
                            bin.throwOutGarbage(waste);
                            informAboutThrowOut();
                        } catch (DustbinIsFull&) {
                            informAboutFullBin();
                        }
                    }
                } while (selectedMenu != 0);
                break;
            }
            case 5 : {
                selectColorOrName("color");
                BottleCap waste = BottleCap(givenString);
                do {
                    handleGarbage();
                    if (selectedMenu == 1) {
                        try {
                            bin.throwOutGarbage(waste);
                            informAboutThrowOut();
                        } catch (BottleCapException&) {
                            std::cout << "\nYou can throw out only pink bottlecup!";
                        } catch (DustbinIsFull&) {
                            informAboutFullBin();
                        }
                    }
                } while (selectedMenu != 0);
                break;
            }
            case 0 : {
                again = false;
            }
        }
    } while (again);
}

void UserInterface::garbageMenu(Dustbin& bin){
    bool again = true;
    do {
        showGarbageOptions();
        showCarret();
        std::cin >> selectedMenu;

        switch (selectedMenu) {
            case 1 : {
                selectColorOrName("name");
                Garbage waste = Garbage(givenString);
                do {
                    handleGarbage();
                    if (selectedMenu == 1) {
                        try {
                            bin.throwOutGarbage(waste);
                            informAboutThrowOut();
                        } catch (DustbinIsFull) {
                            informAboutFullBin();
                        }
                    }
                } while (selectedMenu != 0);
                break;
            }
            case 2 : {
                selectColorOrName("name");
                PlasticGarbage waste = PlasticGarbage(givenString);
                do {
                    handlePlastic();
                    if (selectedMenu == 1) {
                        try {
                            bin.throwOutGarbage(waste);
                            informAboutThrowOut();
                        } catch (DustbinContentError) {
                            std::cout << "\nYou can throw out only clean plastic garbage!";
                        } catch (DustbinIsFull) {
                            informAboutFullBin();
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
                selectColorOrName("name");
                PaperGarbage waste = PaperGarbage(givenString);
                do {
                    handlePaper();
                    if (selectedMenu == 1) {
                        try {
                            bin.throwOutGarbage(waste);
                            informAboutThrowOut();
                        } catch (DustbinContentError) {
                            std::cout << "\nYou can throw out only squeezed paper!";
                        } catch (DustbinIsFull) {
                            informAboutFullBin();
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
            case 0 : {
                again = false;
            }
        }
    } while (again);
}
