// RoomController.cpp - Ricardo

#include "RoomController.h"
#include <iostream>

RoomController::RoomController() {}

void RoomController::addRoom(int number, const std::string& type, double price) {
    rooms.emplace_back(number, type, price);
}

Room* RoomController::findRoomByNumber(int roomNumber) {
    for (auto& room : rooms) {
        if (room.getNumber() == roomNumber) {
            return &room;
        }
    }
    return nullptr;
}

std::string roomTypeToString(RoomType type) {
    switch (type) {
        case RoomType::STANDARD: return "Standard";
        case RoomType::DELUXE:   return "Deluxe";
        default:                 return "Unknown";
    }
}

void RoomController::listRooms() const {
    std::cout << "Lista de Quartos:\n";
    for (const auto& room : rooms) {
        std::cout << "- Quarto #" << room.getNumber()
                  << " (" << room.getType()
                  << "), R$" << room.getPricePerNight() << "\n";
    }
}

