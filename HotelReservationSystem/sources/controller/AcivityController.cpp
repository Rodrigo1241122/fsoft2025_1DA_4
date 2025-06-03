// ActivityController.cpp - Tiago

#include "controller/ActivityController.h"

ActivityController::ActivityController() {}

std::vector<Activity> ActivityController::viewAvailableActivities(const Hotel& hotel) const {
    return hotel.getActivityContainer().getAllActivities();
}

bool ActivityController::addActivityToReservation(std::shared_ptr<Reservation> reserva, const Activity& atividade) {
    if (!reserva) return false;
    reserva->addActivity(atividade);  // Reservation deve ter este método
    return true;
}

bool ActivityController::removeActivityFromReservation(std::shared_ptr<Reservation> reserva, const std::string& activityName) {
    if (!reserva) return false;
    return reserva->removeActivityByName(activityName);  // Reservation deve suportar isto
}
