#include "RoomView.h"
#include <iostream>
#include <string>

// Conversão do enum RoomType para string
std::string roomTypeToString(RoomType type) {
    switch (type) {
        case RoomType::STANDARD: return "Standard";
        case RoomType::SUITE:   return "Double";
        case RoomType::DELUXE:   return "Deluxe";
        default: return "Unknown";
    }
}

void RoomView::printRoom(const Room* r) const {
    std::cout << "Room " << r->getNumber()
              << " - Type: " << roomTypeToString(r->getType())
              << ", Price: " << r->getPricePerNight() << "\n";
}

void RoomView::printRooms(const std::vector<Room>& rooms) const {
    for (const auto& r : rooms)
        printRoom(&r);
}

void RoomView::printRoomNotFound(int number) const {
    std::cout << "Room number " << number << " not found.\n";
}
