#include "PaymentView.h"
#include <iostream>

int PaymentView::menuPayment() const {
    int option;
    std::cout << "\n=== Payment Menu ===\n";
    std::cout << "1. Pay Reservation\n";
    std::cout << "2. View Payment Details\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}

void PaymentView::payReservation() const {
    std::cout << "Paying reservation...\n";
}

void PaymentView::viewPaymentDetails() const {
    std::cout << "Viewing payment details...\n";
}
