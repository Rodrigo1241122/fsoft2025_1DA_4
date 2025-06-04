#include "ActivitiesView.h"
#include <iostream>

int ActivitiesView::menuActivities() const {
    int option;
    std::cout << "\n=== Activities Menu ===\n";
    std::cout << "1. View Activities\n";
    std::cout << "2. Register Activity\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}

void ActivitiesView::viewHotelActivities() const {
    std::cout << "Viewing hotel activities...\n";
}

void ActivitiesView::registerActivity() const {
    std::cout << "Registering for activity...\n";
}
