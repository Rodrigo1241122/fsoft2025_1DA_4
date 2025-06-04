#include "InformationView.h"
#include <iostream>

int InformationView::menuInformation() const {
    int option;
    std::cout << "\n=== Information Menu ===\n";
    std::cout << "1. Hotel Information\n";
    std::cout << "2. Room Information\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}

void InformationView::viewHotelInformation() const {
    std::cout << "Showing hotel information...\n";
}

void InformationView::viewRoomInformation() const {
    std::cout << "Showing room information...\n";
}
