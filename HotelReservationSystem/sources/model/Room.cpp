//Room.cpp - Ricardo

#include "Room.h"

Room::Room(int number, const std::string& type, double price)
    : roomNumber(number), type(type), pricePerNight(price), isAvailable(true) {}

int Room::getRoomNumber() const {
    return roomNumber;
}

std::string Room::getType() const {
    return type;
}

double Room::getPricePerNight() const {
    return pricePerNight;
}

bool Room::getAvailability() const {
    return isAvailable;
}

void Room::setAvailability(bool status) {
    this->isAvailable = status;
}

void Room::addReservation(Reservation* res) {
    reservations.push_back(res);
}

void Room::addActivity(Activity* act) {
    activities.push_back(act);
}
