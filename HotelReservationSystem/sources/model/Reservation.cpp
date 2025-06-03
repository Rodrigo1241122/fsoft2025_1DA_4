// Reservation.cpp - Rodrigo

#include "model/Reservation.h"

int Reservation::ID = 1;

Reservation::Reservation(std::shared_ptr<Client> client, std::shared_ptr<Room> room,
                         const Date& checkIn, const Date& checkOut, float totalPrice,
                         ReservationStatus status)
    : client(client), room(room), checkInDate(checkIn), checkOutDate(checkOut),
      totalPrice(totalPrice), status(status)
{
    reservationID = ID++;
}

Reservation::Reservation(const Reservation& obj)
    : client(obj.client), room(obj.room), checkInDate(obj.checkInDate),
      checkOutDate(obj.checkOutDate), totalPrice(obj.totalPrice), status(obj.status)
{
    reservationID = obj.reservationID;
}

Reservation::~Reservation() {}

std::shared_ptr<Client> Reservation::getClient() const {
    return client;
}

void Reservation::setClient(std::shared_ptr<Client> client) {
    this->client = client;
}

std::shared_ptr<Room> Reservation::getRoom() const {
    return room;
}

void Reservation::setRoom(std::shared_ptr<Room> room) {
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

<<<<<<< HEAD
ReservationStatus Reservation::getStatus() const {
    return status;
}

void Reservation::setStatus(ReservationStatus newStatus) {
    status = newStatus;
}

bool Reservation::operator==(const Reservation& obj) const {
    return this->reservationID == obj.reservationID;
}

bool Reservation::operator==(int id) const {
    return this->reservationID == id;
=======
bool Reservation::operator==(const Reservation& obj) const {
    return reservationID == obj.reservationID;
}

bool Reservation::operator==(int id) const {
    return reservationID == id;
>>>>>>> 9e38deca78b1e02fb621e1c8a0d2e8022301a892
}
