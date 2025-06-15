#include "SearchView.h"
#include <iostream>
#include "data/RoomType.h"
#include "model/Hotel.h" 
#include "Controller.h"
#include <algorithm>
#include "utils.h"
#include <sstream>
#include <limits>
#include "Date.h"

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

void SearchView::chooseRoom(const std::vector<Hotel>& hotels, Controller& controller) const {
    std::cout << "\n==== Search Rooms ====\n";

    std::string desiredRegion;
    double maxPrice;

    std::cout << "Enter desired region (or press ENTER to skip): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, desiredRegion);

    std::cout << "Enter maximum price per night (0 = no limit): ";
    std::cin >> maxPrice;

    std::vector<Room> matchingRooms;

    for (const Hotel& hotel : hotels) {
        if (!desiredRegion.empty() && hotel.getRegion() != desiredRegion) continue;

        for (const Room& room : hotel.getRoomContainer().getAllRooms()) {
            if (room.getPricePerNight() <= maxPrice || maxPrice == 0) {
                matchingRooms.push_back(room);
                std::cout << "\nHotel: " << hotel.getName();
                std::cout << "\nRoom #" << room.getNumber()
                          << " | Price: " << room.getPricePerNight()
                          << " | Type: " << toString(room.getType())
                          << "\n----------------------";
            }
        }
    }

    if (matchingRooms.empty()) {
        std::cout << "No rooms found matching the criteria.\n";
        return;
    }

    std::cout << "\nSelect room numbers to reserve (comma-separated): ";
    std::string input;
    std::cin >> std::ws;
    std::getline(std::cin, input);

    std::vector<Room> selectedRooms;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ',')) {
        int roomNumber = std::stoi(token);
        for (const Room& r : matchingRooms) {
            if (r.getNumber() == roomNumber) {
                selectedRooms.push_back(r);
                break;
            }
        }
    }

    controller.setSelectedRooms(selectedRooms);
    std::cout << selectedRooms.size() << " room(s) selected for reservation.\n";
}

void SearchView::reserveRoom(Controller& controller) const {
    if (!controller.isLoggedIn()) {
        std::cout << "You must be logged in to make a reservation.\n";
        return;
    }

    const std::vector<Room>& selectedRooms = controller.getSelectedRooms();
    if (selectedRooms.empty()) {
        std::cout << "No rooms selected. Please choose rooms before reserving.\n";
        return;
    }

    std::cout << "\n=== Selected Rooms ===\n";
    for (const Room& room : selectedRooms) {
        std::cout << "Room ID: " << room.getId()
                  << ", Type: " << toString(room.getType())
                  << ", Price: " << room.getPricePerNight() << "\n";
    }

    // Get check-in and check-out dates
    Date checkInDate = controller.getDateFromUser("Enter check-in date (dd mm yyyy): ");
    Date checkOutDate = controller.getDateFromUser("Enter check-out date (dd mm yyyy): ");

    // Call the controller to validate dates and calculate total price
    if (!controller.isValidReservation(checkInDate, checkOutDate)) return;

    double totalPrice = controller.calculateTotalPrice(checkInDate, checkOutDate, selectedRooms[0].getPricePerNight());

    std::cout << "Total Price: " << totalPrice << " EUR\n";

    char confirm;
    std::cout << "Do you want to confirm the reservation? (y/n): ";
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        for (const Room& room : selectedRooms) {
            Reservation r(controller.getCurrentClient(), std::make_shared<Room>(room), checkInDate, checkOutDate, totalPrice, ReservationStatus::Pending);
            controller.addReservation(r);
        }

        std::cout << "Reservation(s) completed.\n";
        std::cout << "Go to the Payment section in the Main Menu to pay your reservation.\n";
    } else {
        std::cout << "Reservation cancelled.\n";
    }
}

void SearchView::applyDiscountCoupon(Controller& controller) const {
    if (!controller.isLoggedIn()) {
        std::cout << "You must be logged in to apply a discount.\n";
        return;
    }

    double total = controller.getPendingTotal();
    if (total <= 0) {
        std::cout << "You have no unpaid reservations.\n";
        return;
    }

    std::cout << "Your current total is: " << total << " EUR\n";
    std::cout << "Enter your coupon code: ";
    std::string code;
    std::cin >> code;

    controller.applyDiscountCoupon(code);
    double discountedTotal = controller.getTotalAfterDiscount();

    if ((code != "20" && code != "20porcento" && code != "100" && code != "100porcento") || discountedTotal == total) {
        std::cout << "Invalid coupon code.\n";
        controller.clearDiscount();
    } else {
        std::cout << "Discount applied! New total: " << discountedTotal << " EUR\n";
    }
}

void SearchView::cancelReservation(Controller& controller) const {
    const auto& reservations = controller.getReservations();
    if (reservations.empty()) {
        std::cout << "You have no reservations to cancel.\n";
        return;
    }

    std::cout << "\n=== Your Reservations ===\n";
    for (size_t i = 0; i < reservations.size(); ++i) {
        std::cout << i + 1 << ". ";
        reservations[i].printSummary();  // Método que mostra a informação resumida da reserva
    }

    std::cout << "0. Cancel\n";
    std::cout << "Choose reservation to cancel: ";
    int choice;
    std::cin >> choice;

    if (choice == 0 || choice > (int)reservations.size()) return;

    const Reservation& res = reservations[choice - 1];

    std::cout << "Are you sure you want to cancel this reservation? (y/n): ";
    char confirm;
    std::cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') return;

    double refund = 0;
    if (res.isPaid()) {
        refund = res.getTotalPrice();
        controller.getCurrentClient()->addBalance(refund);
        std::cout << "Reservation was paid. €" << refund << " refunded to your account.\n";
    } else {
        std::cout << "Reservation was not paid. No refund issued.\n";
    }

    controller.removeReservation(choice - 1);
    std::cout << "Reservation cancelled successfully.\n";
}

void SearchView::printAvailableRooms(const std::vector<const Room*>& rooms) const {
    std::cout << "\n=== Available Rooms ===\n";
    for (const Room* room : rooms) {
        std::cout << "Room ID: " << room->getId() << "\n";
        std::cout << "Type: " << toString(room->getType()) << "\n";
        std::cout << "Price: " << room->getPricePerNight() << "\n";
        std::cout << "------------------------\n";
    }
}

void SearchView::printNoAvailableRooms() const {
    std::cout << "There are no available rooms at the moment.\n";
}

void SearchView::searchAvailableRooms(const std::vector<Hotel>& hotels) const {
    std::vector<const Room*> availableRooms;

    for (const auto& hotel : hotels) {
        for (const auto& room : hotel.getRoomContainer().getAll()) {
            if (room.isAvailable()) {
                availableRooms.push_back(&room);
            }
        }
    }

    if (availableRooms.empty()) {
        printNoAvailableRooms();
    } else {
        printAvailableRooms(availableRooms);
    }
}
