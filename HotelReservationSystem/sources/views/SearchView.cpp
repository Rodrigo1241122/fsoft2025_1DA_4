#include "SearchView.h"
#include <iostream>

int SearchView::menuSearch() const {
    int option;
    std::cout << "\n=== Search Menu ===\n";
    std::cout << "1. Search Rooms\n";
    std::cout << "2. Choose Room\n";
    std::cout << "3. View Info\n";
    std::cout << "4. Reserve Room\n";
    std::cout << "5. Apply Discount\n";
    std::cout << "6. Cancel Reservation\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}

void SearchView::searchAvailableRooms() const {
    std::cout << "Searching available rooms...\n";
}

void SearchView::chooseRoom() const {
    std::cout << "Choosing room...\n";
}

void SearchView::reserveRoom() const {
    std::cout << "Reserving room...\n";
}

void SearchView::applyDiscountCoupon() const {
    std::cout << "Applying discount coupon...\n";
}

void SearchView::cancelReservation() const {
    std::cout << "Cancelling reservation...\n";
}
