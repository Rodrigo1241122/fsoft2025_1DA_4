#ifndef HEADERS_MODEL_RESERVATION_H_
#define HEADERS_MODEL_RESERVATION_H_

#include <memory>
#include "model/Client.h"
#include "model/Room.h"
#include "model/Date.h"
#include "Hotel.h"

enum class ReservationStatus { Pending, Confirmed, Canceled };

class Reservation {
private:
    static int ID;
    int reservationID;
    std::shared_ptr<Client> client;
    std::shared_ptr<Room> room;
    Date checkInDate;
    Date checkOutDate;
    double totalPrice;
    double discountedPrice = -1;
    bool paid = false;
    ReservationStatus status;

public:
    Reservation(std::shared_ptr<Client> client, std::shared_ptr<Room> room,
                const Date& checkIn, const Date& checkOut, float totalPrice,
                ReservationStatus status);
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

    void setTotalPrice(float price);
    int getReservationID() const;
    void setReservationID(int id);

    ReservationStatus getStatus() const;
    void setStatus(ReservationStatus newStatus);

    bool operator==(const Reservation& obj) const;
    bool operator==(int id) const;

    bool isPaid() const;
    void markAsPaid();

    void setDiscountedPrice(double price);
    double getTotalPrice() const;

    void printSummary() const;  // Declaração de printSummary

    void setPaid(bool status);  // Declaração de setPaid
};

#endif /* HEADERS_MODEL_RESERVATION_H_ */
