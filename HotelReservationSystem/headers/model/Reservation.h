#ifndef HEADERS_MODEL_RESERVATION_H_
#define HEADERS_MODEL_RESERVATION_H_

#include <memory>
#include <vector>
#include "model/Room.h"
#include "model/Date.h"
#include "Hotel.h"

class Client;

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
    int hotelId;
    std::vector<int> activityIds;
    std::vector<int> serviceIds;

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
    double getTotalPrice() const;
    void setDiscountedPrice(double price);

    int getReservationID() const;
    void setReservationID(int id);

    const std::vector<int>& getActivityIds() const;
    const std::vector<int>& getServicesIds() const;
    int getHotelId() const;
    void setHotelId(int id);

    ReservationStatus getStatus() const;
    void setStatus(ReservationStatus newStatus);

    bool operator==(const Reservation& obj) const;
    bool operator==(int id) const;

    bool isPaid() const;
    void markAsPaid();
    void setPaid(bool status);

    bool hasActivity(int activityId) const;
    void addActivity(int activityId);

    void printSummary() const;
};

#endif /* HEADERS_MODEL_RESERVATION_H_ */
