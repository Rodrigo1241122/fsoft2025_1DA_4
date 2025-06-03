// Reservation.h - Rodrigo

#ifndef HEADERS_MODEL_RESERVATION_H_
#define HEADERS_MODEL_RESERVATION_H_

#include <memory>
#include "model/Client.h"
#include "model/Room.h"
#include "model/Date.h"
#include "data/ReservationStatus.h"

class Reservation {
private:
    static int ID;
    int reservationID;
    std::shared_ptr<Client> client;
    std::shared_ptr<Room> room;
    Date checkInDate;
    Date checkOutDate;
    float totalPrice;
    ReservationStatus status;

public:
    Reservation(std::shared_ptr<Client> client, std::shared_ptr<Room> room,
                const Date& checkIn, const Date& checkOut, float totalPrice,
                ReservationStatus status = ReservationStatus::CONFIRMED);

    Reservation(const Reservation& obj);
    ~Reservation();

    std::shared_ptr<Client> getClient() const;
    void setClient(std::shared_ptr<Client> client);

    std::shared_ptr<Room> getRoom() const;
    void setRoom(std::shared_ptr<Room> room);

    const Date& getCheckInDate() const;
    void setCheckInDate(const Date& date);

    const Date& getCheckOutDate() const;
    void setCheckOutDate(const Date& date);

    float getTotalPrice() const;
    void setTotalPrice(float price);

    int getReservationID() const;
    void setReservationID(int id);

    ReservationStatus getStatus() const;
    void setStatus(ReservationStatus status);

    bool operator==(const Reservation& obj) const;
    bool operator==(int id) const;
};

#endif /* HEADERS_MODEL_RESERVATION_H_ */
