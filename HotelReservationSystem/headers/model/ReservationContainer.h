// ReservationContainer.h - Tiago

#ifndef HEADERS_MODEL_RESERVATIONCONTAINER_H_
#define HEADERS_MODEL_RESERVATIONCONTAINER_H_

#include <vector>
#include <memory>
#include "Reservation.h"

class ReservationContainer {
private:
    std::vector<std::shared_ptr<Reservation>> reservations;

public:
    void addReservation(const std::shared_ptr<Reservation>& reservation);
    std::vector<std::shared_ptr<Reservation>>& getAllReservations();
    const std::vector<std::shared_ptr<Reservation>>& getAllReservations() const;
};

#endif /* HEADERS_MODEL_RESERVATIONCONTAINER_H_ */
