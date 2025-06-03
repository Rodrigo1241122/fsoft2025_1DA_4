// ReservationController.h - Rodrigo

#ifndef CONTROLLERS_RESERVATIONCONTROLLER_H_
#define CONTROLLERS_RESERVATIONCONTROLLER_H_

#include "model/Reservation.h"
#include "model/Service.h"
#include "model/Activity.h"
#include "model/Coupon.h"
#include <vector>

class ReservationController {
public:
    Reservation* makeReservation(Client* client, Room* room, const Date& checkIn, const Date& checkOut, float price);
    bool cancelReservation(int reservationID);
    Reservation* findReservationByID(int id);
    std::vector<Reservation*> listReservationsForClient(int clientID) const;

    void updateReservationServices(int reservationID, const std::vector<Service*>& newServices);
    void updateReservationActivities(int reservationID, const std::vector<Activity*>& newActivities);
    float calculateTotalPrice(int reservationID, const Coupon* coupon = nullptr) const;

private:
    std::vector<Reservation*> reservations;
};

#endif // CONTROLLERS_RESERVATIONCONTROLLER_H_
