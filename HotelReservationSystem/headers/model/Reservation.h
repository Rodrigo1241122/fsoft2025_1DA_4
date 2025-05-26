#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <memory>
#include "Client.h"
#include "Room.h"
#include "Date.h"

class Reservation {
private:
    int id;
    std::shared_ptr<Client> client;
    std::shared_ptr<Room> room;
    Date checkInDate;
    Date checkOutDate;
    double totalPrice;

public:
    Reservation(int id,
                std::shared_ptr<Client> client,
                std::shared_ptr<Room> room,
                const Date& checkInDate,
                const Date& checkOutDate,
                double totalPrice);

    int getId() const;
    std::shared_ptr<Client> getClient() const;
    std::shared_ptr<Room> getRoom() const;
    Date getCheckInDate() const;
    Date getCheckOutDate() const;
    double getTotalPrice() const;
};

#endif // RESERVATION_H