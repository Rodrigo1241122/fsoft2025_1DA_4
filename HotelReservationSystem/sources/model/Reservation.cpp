#include "model/Reservation.h"
#include "model/Room.h"
#include "Hotel.h"
#include "Client.h"
#include <iostream>
#include <algorithm>

// =======================
// Definição do ID estático
// =======================
int Reservation::ID = 1;

// =======================
// Construtores & Destrutor
// =======================

Reservation::Reservation(std::shared_ptr<Client> client, std::shared_ptr<Room> room,
                         const Date& checkIn, const Date& checkOut, float totalPrice,
                         ReservationStatus status)
    : client(client), room(room), checkInDate(checkIn), checkOutDate(checkOut),
      totalPrice(totalPrice), status(status)
{
    reservationID = ID++;
    if (room && room->getHotel()) {
        hotelId = room->getHotel()->getId();
    } else {
        hotelId = -1;
    }
}

Reservation::Reservation(const Reservation& obj)
    : client(obj.client), room(obj.room), checkInDate(obj.checkInDate),
      checkOutDate(obj.checkOutDate), totalPrice(obj.totalPrice), status(obj.status),
      paid(obj.paid), discountedPrice(obj.discountedPrice), hotelId(obj.hotelId),
      activityIds(obj.activityIds) // Copiar também as atividades
{
    reservationID = obj.reservationID;
}

Reservation::~Reservation() {}

// =======================
// Getters & Setters
// =======================

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
    if (room && room->getHotel()) {
        hotelId = room->getHotel()->getId();
    } else {
        hotelId = -1;
    }
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

void Reservation::setTotalPrice(float price) {
    totalPrice = price;
}

double Reservation::getTotalPrice() const {
    if (discountedPrice >= 0)
        return discountedPrice;
    return totalPrice;
}

void Reservation::setDiscountedPrice(double price) {
    discountedPrice = price;
}

// =======================
// Métodos de ID
// =======================

int Reservation::getReservationID() const {
    return reservationID;
}

void Reservation::setReservationID(int id) {
    reservationID = id;
}

int Reservation::getHotelId() const {
    return hotelId;
}

void Reservation::setHotelId(int id) {
    hotelId = id;
}

const std::vector<int>& Reservation::getActivityIds() const {
    return activityIds;
}

const std::vector<int>& Reservation::getServicesIds() const {
    return serviceIds;
}
// =======================
// Estado da Reserva & Comparação
// =======================

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
}

// =======================
// Pagamento
// =======================

bool Reservation::isPaid() const {
    return paid;
}

void Reservation::markAsPaid() {
    paid = true;
}

void Reservation::setPaid(bool status) {
    paid = status;
}

// =======================
// Atividades
// =======================

bool Reservation::hasActivity(int activityId) const {
    return std::find(activityIds.begin(), activityIds.end(), activityId) != activityIds.end();
}

void Reservation::addActivity(int activityId) {
    if (!hasActivity(activityId)) {
        activityIds.push_back(activityId);
    }
}

// =======================
// Utilitários
// =======================

void Reservation::printSummary() const {
    std::cout << "Reservation ID: " << reservationID << "\n";
    std::cout << "Hotel: " << hotelId << "\n";
    std::cout << "Room: " << room->getNumber() << "\n";
    std::cout << "Check-in: ";
    int day, month, year;
    checkInDate.getDate(day, month, year);
    std::cout << day << "/" << month << "/" << year << "\n";
    std::cout << "Check-out: ";
    checkOutDate.getDate(day, month, year);
    std::cout << day << "/" << month << "/" << year << "\n";
    std::cout << "Total Price: " << getTotalPrice() << " EUR\n";
    std::cout << "Paid: " << (isPaid() ? "Yes" : "No") << "\n";
}
