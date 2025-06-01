// Reservation.cpp - rodrigo

#include "Reservation.h"

int Reservation::ID = 0;

Reservation::Reservation(Client* client, Room* room, const Date& checkIn, const Date& checkOut, float totalPrice)
    : client(client), room(room), checkInDate(checkIn), checkOutDate(checkOut), totalPrice(totalPrice) {
    reservationID = ++ID;
}

Reservation::Reservation(const Reservation& obj)
    : client(obj.client), room(obj.room), checkInDate(obj.checkInDate), checkOutDate(obj.checkOutDate), totalPrice(obj.totalPrice), reservationID(obj.reservationID) {
}

Reservation::~Reservation() {
    // Se o objeto é dono do ponteiro, deve deletar, mas depende da arquitetura do projeto
    // delete client;
    // delete room;
}

Client* Reservation::getClient() const {
    return client;
}

void Reservation::setClient(Client* client) {
    this->client = client;
}

Room* Reservation::getRoom() const {
    return room;
}

void Reservation::setRoom(Room* room) {
    this->room = room;
}

const Date& Reservation::getCheckInDate() const {
    return checkInDate;
}

void Reservation::setCheckInDate(const Date& date) {
    checkInDate = date;
}

const Date& Reservation::getCheckOutDate() const {
    return checkOutDate;
}

void Reservation::setCheckOutDate(const Date& date) {
    checkOutDate = date;
}

float Reservation::getTotalPrice() const {
    return totalPrice;
}

void Reservation::setTotalPrice(float price) {
    totalPrice = price;
}

int Reservation::getReservationID() const {
    return reservationID;
}

void Reservation::setReservationID(int id) {
    reservationID = id;
}

bool Reservation::operator==(const Reservation& obj) const {
    return reservationID == obj.reservationID;
}

bool Reservation::operator==(int id) const {
    return reservationID == id;
}
