#include "ServiceView.h"
#include <iostream>
#include "ServiceUnavailableException.h"
#include <limits>
#include <algorithm>
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

// Mostra os serviços reais do hotel da reserva atual
void ServiceView::viewAvailableServices(const Controller& controller) const {
    std::cout << "\n=== Available Services in All Hotels ===\n";
    const auto& hoteis = controller.getHotels();
    for (const Hotel& hotel : hoteis) {
        const auto& services = hotel.getServiceContainer().getAllServices();
        if (!services.empty()) {
            std::cout << "Hotel: " << hotel.getName() << "\n";
            for (const auto& service : services) {
                std::cout << "  ID: " << service.getId()
                          << " - " << service.getName()
                          << " - " << service.getDescription()
                          << " (Price: " << service.getPrice() << " EUR)\n";
            }
        }
    }
    std::cout << "0. Back\n";
}
void ServiceView::requestService(Controller& controller) {
    if (!controller.isLoggedIn()) {
        std::cout << "You must be logged in to request a service.\n";
        return;
    }

    // Garante que o cliente tem pelo menos uma reserva
    if (!controller.hasReservation()) {
        std::cout << "You must have at least one reservation to request a service.\n";
        return;
    }

    // Obtem apenas os serviços do hotel da reserva atual
    auto services = controller.getServicesForCurrentReservationHotel();
    if (services.empty()) {
        std::cout << "No services available for your reservation's hotel.\n";
        return;
    }

    // Mostra só estes serviços
    std::cout << "\n=== Available Services ===\n";
    for (const auto& service : services) {
        std::cout << "  ID: " << service.getId()
                  << " - " << service.getName()
                  << " - " << service.getDescription()
                  << " (Price: " << service.getPrice() << " EUR)\n";
    }
    std::cout << "0. Back\n";

    int id;
    std::cout << "\nEnter the ID of the service you want to request: ";
    std::cin >> id;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.\n";
        return;
    }
    if (id == 0) return;

    // Verifica se o ID pertence a um serviço deste hotel
    auto it = std::find_if(services.begin(), services.end(),
        [id](const Service& s) { return s.getId() == id; });

    if (it == services.end()) {
        std::cout << "Invalid service ID for your reservation's hotel.\n";
        return;
    }

    if (controller.hasService(id)) {
        std::cout << "You have already requested this service.\n";
        return;
    }

    try {
        double price = it->getPrice(); // Pega o preço do serviço escolhido
        controller.addServiceToReservation(id);
        controller.addToPendingAmount(price);
        std::cout << "Service added to your reservation! Price: " << price << " EUR\n";
    } catch (const ServiceUnavailableException& e) {
        std::cout << "Error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}
