#include "MainView.h"
#include <iostream>
#include <limits>

int MainView::menuMain() const {
    int option;
    while (true) {
        std::cout << "\n=== Main Menu ===\n";
        std::cout << "1. Account\n";
        std::cout << "2. Search\n";
        std::cout << "3. Services\n";
        std::cout << "4. Reviews\n";
        std::cout << "5. Payment\n";
        std::cout << "6. Activities\n";
        std::cout << "0. Exit\n";
        std::cout << "Option: ";
        std::cin >> option;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid character! The option you entered has no effect.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return option;
        }
    }
}
