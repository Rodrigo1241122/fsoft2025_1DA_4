#include "model/Reservation.h"
#include "model/Room.h"
#include "Hotel.h"
#include <iostream>

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

void Reservation::setTotalPrice(float price) {
    totalPrice = price;
}

int Reservation::getReservationID() const {
    return reservationID;
}

void Reservation::setReservationID(int id) {
    reservationID = id;
}

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

void Reservation::markAsPaid() {
    paid = true;
}

void Reservation::setDiscountedPrice(double price) {
    discountedPrice = price;
}

double Reservation::getTotalPrice() const {
    if (discountedPrice >= 0)  // Se o preço com desconto for válido
        return discountedPrice;
    return totalPrice;  // Caso contrário, retorna o preço total original
}

void Reservation::printSummary() const {
    std::cout << "Reservation ID: " << reservationID << "\n";  // Exibe o ID da reserva
    std::cout << "Hotel: " << room->getHotel()->getName() << "\n";  // Exibe o nome do hotel
    std::cout << "Room: " << room->getNumber() << "\n";  // Exibe o número do quarto
    std::cout << "Check-in: ";
    int day, month, year;
    checkInDate.getDate(day, month, year);  // Obtém a data de check-in
    std::cout << day << "/" << month << "/" << year << "\n";  // Exibe a data de check-in
    std::cout << "Check-out: ";
    checkOutDate.getDate(day, month, year);  // Obtém a data de check-out
    std::cout << day << "/" << month << "/" << year << "\n";  // Exibe a data de check-out
    std::cout << "Total Price: " << getTotalPrice() << " EUR\n";  // Exibe o preço total
    std::cout << "Paid: " << (isPaid() ? "Yes" : "No") << "\n";  // Exibe se foi pago ou não
}

void Reservation::setPaid(bool status) {
    paid = status;  // Define o status de pago da reserva
}

bool Reservation::isPaid() const {
    return paid;  // Retorna se a reserva foi paga ou não
}