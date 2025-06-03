// ReservationController.h - Rodrigo

#include "headers/controllers/ReservationController.h"
#include "headers/utils/DateUtils.h"
#include "headers/utils/Logger.h"

Reservation* ReservationController::makeReservation(Client* client, Room* room, const Date& checkIn, const Date& checkOut, float price) {
    if (!DateUtils::isCheckInBeforeCheckOut(checkIn, checkOut)) {
        Logger::error("Invalid dates: check-in must be before check-out.");
        return nullptr;
    }

    Reservation* reservation = new Reservation(client, room, checkIn, checkOut, price);
    reservations.push_back(reservation);
    Logger::info("Reservation created successfully.");
    return reservation;
}

bool ReservationController::cancelReservation(int reservationID) {
    for (auto it = reservations.begin(); it != reservations.end(); ++it) {
        if ((**it) == reservationID) {
            delete *it;
            reservations.erase(it);
            Logger::info("Reservation canceled.");
            return true;
        }
    }
    Logger::error("Reservation not found.");
    return false;
}

Reservation* ReservationController::findReservationByID(int id) {
    for (Reservation* r : reservations) {
        if (*r == id)
            return r;
    }
    return nullptr;
}

std::vector<Reservation*> ReservationController::listReservationsForClient(int clientID) const {
    std::vector<Reservation*> result;
    for (Reservation* r : reservations) {
        if (r->getClient()->getClientID() == clientID)
            result.push_back(r);
    }
    return result;
}

void ReservationController::updateReservationServices(int reservationID, const std::vector<Service*>& newServices) {
    Reservation* res = findReservationByID(reservationID);
    if (res) {
        res->setServices(newServices);
        Logger::info("Updated services in reservation.");
    } else {
        Logger::error("Reservation not found.");
    }
}

void ReservationController::updateReservationActivities(int reservationID, const std::vector<Activity*>& newActivities) {
    Reservation* res = findReservationByID(reservationID);
    if (res) {
        res->setActivities(newActivities);
        Logger::info("Updated activities in reservation.");
    } else {
        Logger::error("Reservation not found.");
    }
}

float ReservationController::calculateTotalPrice(int reservationID, const Coupon* coupon) const {
    Reservation* res = nullptr;
    for (Reservation* r : reservations) {
        if (r->getReservationID() == reservationID) {
            res = r;
            break;
        }
    }

    if (!res) {
        Logger::error("Reservation not found.");
        return 0.0f;
    }

    float total = res->getTotalPrice();

    for (Service* s : res->getServices()) {
        total += s->getPrice();
    }

    for (Activity* a : res->getActivities()) {
        total += 20.0f; // Exemplo: preço fixo por atividade
    }

    if (coupon) {
        total *= (1 - coupon->getDiscountPercentage() / 100.0f);
    }

    return total;
}
