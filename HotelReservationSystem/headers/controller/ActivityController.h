// ActivityController.h - Tiago

#ifndef CONTROLLER_ACTIVITYCONTROLLER_H
#define CONTROLLER_ACTIVITYCONTROLLER_H

#include "model/Hotel.h"
#include "model/Activity.h"
#include "model/Reservation.h"
#include <vector>
#include <string>
#include <memory>

class ActivityController {
public:
    ActivityController();

    std::vector<Activity> viewAvailableActivities(const Hotel& hotel) const;

    bool addActivityToReservation(std::shared_ptr<Reservation> reserva, const Activity& atividade);
    bool removeActivityFromReservation(std::shared_ptr<Reservation> reserva, const std::string& activityName);
};

#endif // CONTROLLER_ACTIVITYCONTROLLER_H
