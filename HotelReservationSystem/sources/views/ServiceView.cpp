#include "ServiceView.h"
#include <iostream>
#include "ServiceUnavailableException.h"
#include <limits>
#include "Controller.h"

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
    std::cout << "\n=== Available Services ===\n";
    std::cout << "1. Breakfast - Enjoy a fresh breakfast buffet. (Price: 15 EUR)\n";
    std::cout << "2. Airport Transfer - Transport to/from the airport. (Price: 25 EUR)\n";
    std::cout << "3. Spa Access - Full-day access to the hotel spa. (Price: 30 EUR)\n";
    std::cout << "4. Room Cleaning - Daily cleaning service. (Price: 10 EUR)\n";
    std::cout << "0. Back\n";
}


void ServiceView::requestService(Controller& controller) {
    if (!controller.isLoggedIn()) {
        std::cout << "You must be logged in to request a service.\n";
        return;
    }

    if (controller.getReservations().empty()) {
        std::cout << "You must have at least one reservation to request a service.\n";
        return;
    }

    viewAvailableServices();

    int id;
    std::cout << "\nEnter the ID of the service you want to request: ";
    std::cin >> id;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.\n";
        return;
    }

    if (controller.hasService(id)) {
        std::cout << "You have already requested this service.\n";
        return;
    }

    try {
        double price = controller.getServicePriceById(id);   // deve estar implementado
        controller.addServiceToReservation(id);              // adiciona o ID à lista do utilizador
        controller.addToPendingAmount(price);                // adiciona ao valor a pagar
        std::cout << "Service added to your reservation! Price: " << price << " EUR\n";
    } catch (const ServiceUnavailableException& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

