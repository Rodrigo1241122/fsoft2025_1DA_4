#include "ServiceView.h"
#include <iostream>

int ServiceView::menuService() const {
    int option;
    std::cout << "\n=== Service Menu ===\n";
    std::cout << "1. View Services\n";
    std::cout << "2. Request Service\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}

void ServiceView::viewAvailableServices() const {
    std::cout << "Viewing available services...\n";
}

void ServiceView::requestService() const {
    std::cout << "Requesting service...\n";
}
