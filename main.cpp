#include <iostream>
#include "UserInterface.h"

int main() {
    std::cout << "\nWelcome!\nThis is the waste recycling suite.\n\n";
    UserInterface ui = UserInterface();
    ui.process();
    return 0;
}