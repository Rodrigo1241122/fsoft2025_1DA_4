// PaymentView.cpp - Tiago

#include "PaymentView.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Controller.h"

int PaymentView::menuPayment() const {
    int option;
    std::cout << "\n--- Payment Menu ---\n";
    std::cout << "1. Pay Reservation\n";
    std::cout << "2. View Payment Details\n";
    std::cout << "0. Back to Main Menu\n";
    std::cout << "Choose an option: ";
    std::cin >> option;
    return option;
}

void PaymentView::printReceipt(const Controller& controller) const {
    auto client = controller.getCurrentClient();
    if (!client) {
        std::cout << "You need to be logged in to view payment details.\n";
        return;
    }

    double amount = controller.getLastPaymentAmount();
    if (amount <= 0.0) {
        std::cout << "No payments have been made yet.\n";
        return;
    }

    time_t paymentTime = controller.getLastPaymentDate();
    tm* paymentDate = localtime(&paymentTime);

    std::cout << "===============================\n";
    std::cout << "        PAYMENT RECEIPT       \n";
    std::cout << "===============================\n";
    std::cout << "Client: " << client->getName() << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Amount Paid: " << amount << " EUR\n";
    std::cout << "Remaining Balance: " << client->getBalance() << " EUR\n";
    std::cout << "Payment Date: ";
    std::cout << std::put_time(paymentDate, "%d-%m-%Y %H:%M:%S") << "\n";
    std::cout << "===============================\n";
}

void PaymentView::payReservation(Controller& controller) {
    if (!controller.isLoggedIn()) {
        std::cout << "You must be logged in to pay for a reservation.\n";
        return;
    }

    double totalToPay = controller.getTotalAfterDiscount();
    double currentBalance = controller.getCurrentClient()->getBalance();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your balance: " << currentBalance << " EUR\n";
    std::cout << "Amount due: " << totalToPay << " EUR\n";

    if (totalToPay <= 0.0) {
        std::cout << "No pending amount to pay.\n";
        return;
    }

    char confirm;
    std::cout << "Do you want to proceed with the payment? (y/n): ";
    std::cin >> confirm;

    if (confirm != 'y' && confirm != 'Y') {
        std::cout << "Payment cancelled.\n";
        return;
    }

    // Usa a função de pagamento do controller, que faz tudo corretamente
    bool success = controller.payPending();

    if (success) {
        controller.clearDiscount(); // Limpa o desconto após pagamento!
        std::cout << "Payment successful!\n";
    }
}
