#include "model/Room.h"

Room::Room() {
    number = 0;
    pricePerNight = 0.0;
    type = RoomType::STANDARD;
    available = true;
    id = 0;
    hotel = nullptr;  // Inicializa o hotel como nullptr
}

Room::Room(int id, int number, double pricePerNight, RoomType type, std::shared_ptr<Hotel> hotel)
    : id(id), number(number), pricePerNight(pricePerNight), type(type), available(true), hotel(hotel) {}

Room::Room(const Room& other)
    : id(other.id), number(other.number), pricePerNight(other.pricePerNight),
      type(other.type), available(other.available), hotel(other.hotel) {}

int Room::getId() const {
    return id;
}

void Room::setId(int id) {
    this->id = id;
}

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

bool Room::isAvailable() const {
    return available;
}

void Room::setAvailable(bool value) {
    available = value;
}

bool Room::operator==(const Room& other) const {
    return number == other.number;
}

std::shared_ptr<Hotel> Room::getHotel() const {
    return hotel;  // Retorna o ponteiro para o hotel associado ao quarto
}
