#include "MainView.h"
#include <iostream>

int MainView::menuMain() const {
    int option;
    std::cout << "=== Main Menu ===\n";
    std::cout << "1. Account\n";
    std::cout << "2. Search\n";
    std::cout << "3. Services\n";
    std::cout << "4. Reviews\n";
    std::cout << "5. Payment\n";
    std::cout << "6. Activities\n";
    std::cout << "0. Exit\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}
