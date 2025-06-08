// ReservationContainer.cpp - Tiago

#include "model/ReservationContainer.h"
#include "model/Reservation.h"

void ReservationContainer::addReservation(const std::shared_ptr<Reservation>& reservation) {
    reservations.push_back(reservation);
}

std::vector<std::shared_ptr<Reservation>>& ReservationContainer::getAllReservations() {
    return reservations;
}

const std::vector<std::shared_ptr<Reservation>>& ReservationContainer::getAllReservations() const {
    return reservations;
}
