#include "RoomView.h"
#include <iostream>

void RoomView::printRoom(const Room* r) const {
    std::cout << "Room " << r->getNumber()
              << " - Type: " << r->getType()
              << ", Price: " << r->getPrice() << "\n";
}

void RoomView::printRooms(const std::vector<Room>& rooms) const {
    for (const auto& r : rooms)
        printRoom(&r);
}

void RoomView::printRoomNotFound(int number) const {
    std::cout << "Room number " << number << " not found.\n";
}
