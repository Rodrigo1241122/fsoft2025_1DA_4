#include "AccountView.h"
#include <iostream>

int AccountView::menuAccount() const {
    int option;
    std::cout << "\n=== Account Menu ===\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Login\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}

void AccountView::createAccount() const {
    std::cout << "Creating account...\n";
}

void AccountView::login() const {
    std::cout << "Logging in...\n";
}
