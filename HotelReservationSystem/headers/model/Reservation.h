// Reservation.h - rodrigo

#ifndef HEADERS_MODEL_RESERVATION_H_
#define HEADERS_MODEL_RESERVATION_H_

#include <string>
#include "Client.h"
#include "Room.h"
#include "Date.h"
#include "ReservationStatus.h"

class Reservation {
private:
    static int ID;
    int reservationID;
    Client* client;
    Room* room;
    Date checkInDate;
    Date checkOutDate;
    float totalPrice;

public:
    Reservation(Client* client, Room* room, const Date& checkIn, const Date& checkOut, float totalPrice);
    Reservation(const Reservation& obj);
    ~Reservation();

    Client* getClient() const;
    void setClient(Client* client);

    Room* getRoom() const;
    void setRoom(Room* room);

    const Date& getCheckInDate() const;
    void setCheckInDate(const Date& date);

    const Date& getCheckOutDate() const;
    void setCheckOutDate(const Date& date);

    float getTotalPrice() const;
    void setTotalPrice(float price);

    int getReservationID() const;
    void setReservationID(int id);

    bool operator == (const Reservation& obj) const;
    bool operator == (int id) const;
};

<<<<<<< HEAD
#endif /* HEADERS_MODEL_RESERVATION_H_ */
=======
#endif /* HEADERS_MODEL_RESERVATION_H_*/
>>>>>>> f476aeca8a9d0ceb8c31a9de5b0084cea7a20e50
