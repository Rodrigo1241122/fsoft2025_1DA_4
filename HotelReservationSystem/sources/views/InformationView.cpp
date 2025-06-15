#include "InformationView.h"
#include <iostream>

InformationView::InformationView(const std::vector<Hotel>& hotels) : hotels(hotels) {}

int InformationView::menuInformation() const {
    int option;
    std::cout << "\n=== Information Menu ===\n";
    std::cout << "1. View Hotel Info\n";
    std::cout << "2. View Room Info\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}

void InformationView::viewInfo() const {
    std::cout << "\n--- Hotel List ---\n";
    for (const auto& hotel : hotels) {
        std::cout << "Hotel: " << hotel.getName() << "\n"
                  << "Location: " << hotel.getLocation() << "\n"
                  << "Stars: " << hotel.getStars() << "\n"
                  << "Number of Rooms: " << hotel.getRoomCount() << "\n"
                  << "------------------------\n";
    }
}

void InformationView::viewHotelInfo() const {
    std::cout << "\n=== Hotel Information ===\n\n";

    std::cout << "1. Hotel Mar Azul (Porto) - 4.5 stars\n";
    std::cout << "   A charming seaside hotel with Atlantic views. Perfect for romantic getaways.\n\n";

    std::cout << "2. Serra Palace (Braga) - 5 stars\n";
    std::cout << "   Located atop northern mountains, offering luxury merged with nature.\n\n";

    std::cout << "3. Sol Nascente (Faro) - 3 stars\n";
    std::cout << "   Cozy accommodation in the heart of the Algarve. Simple but comfortable.\n\n";

    std::cout << "4. Montanha Real (Viseu) - 4 stars\n";
    std::cout << "   Ideal for those seeking peace and fresh mountain air in central Portugal.\n\n";

    std::cout << "5. Lagoa Serena (Aveiro) - 3 stars\n";
    std::cout << "   Overlooking the lagoon, known for its peaceful ambiance and natural surroundings.\n\n";

    std::cout << "6. Castelo do Sol (Lisbon) - 5 stars\n";
    std::cout << "   A premium hotel in the historic center of Lisbon. Tradition meets modern comfort.\n\n";

}

void InformationView::viewRoomInformation() const {
    std::cout << "\n=== Room Type Information ===\n\n";

    std::cout << "STANDARD:\n";
    std::cout << "   Basic and affordable room. Includes a single bed, TV, and Wi-Fi. Ideal for short stays.\n\n";

    std::cout << "SUITE:\n";
    std::cout << "   A luxurious and spacious room, perfect for couples and for a very nice stay.\n\n";

    std::cout << "DELUXE:\n";
    std::cout << "   Premium room with a king-size bed, private balcony, minibar, and panoramic view.\n\n";

}

