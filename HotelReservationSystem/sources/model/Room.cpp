// Room.cpp - Tiago

#include "model/Room.h"

Room::Room() {
    number = 0;
    pricePerNight = 0.0;
    type = RoomType::STANDARD;
}

Room::Room(int number, double pricePerNight, RoomType type)
    : number(number), pricePerNight(pricePerNight), type(type) {}

Room::Room(const Room& other)
    : number(other.number), pricePerNight(other.pricePerNight), type(other.type) {}

int Room::getNumber() const {
    return number;
}

void Room::setNumber(int number) {
    this->number = number;
}

double Room::getPricePerNight() const {
    return pricePerNight;
}

void Room::setPricePerNight(double price) {
    pricePerNight = price;
}

RoomType Room::getType() const {
    return type;
}

void Room::setType(RoomType type) {
    this->type = type;
}

bool Room::operator==(const Room& other) const {
    return number == other.number;
}
