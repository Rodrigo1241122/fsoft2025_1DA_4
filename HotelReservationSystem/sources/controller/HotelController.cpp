//HotelController.cpp - Ricardo

#include "HotelController.h"
#include <iostream>

HotelController::HotelController() {}

void HotelController::addHotel(const std::string& name, const std::string& location) {
    hotels.emplace_back(name, location);
}

Hotel* HotelController::findHotelByName(const std::string& name) {
    for (auto& hotel : hotels) {
        if (hotel.getName() == name) {
            return &hotel;
        }
    }
    return nullptr;
}

void HotelController::listHotels() const {
    std::cout << "Lista de Hotéis:\n";
    for (const auto& hotel : hotels) {
        std::cout << "- " << hotel.getName() << " em " << hotel.getLocation() << "\n";
    }
}