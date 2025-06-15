// ActivityContainer.cpp - Tiago

#include "model/ActivityContainer.h"
#include "ActivityUnavailableException.h"

void ActivityContainer::addActivity(const Activity& activity) {
    activities.push_back(activity);
}

std::vector<Activity>& ActivityContainer::getAllActivities() {
    return activities;
}

const std::vector<Activity>& ActivityContainer::getAllActivities() const {
    return activities;
}
double ActivityContainer::getPriceById(int activityId) const {
    for (const Activity& a : activities) {
        if (a.getId() == activityId) {
            return a.getPrice();
        }
    }
    throw ActivityUnavailableException("Activity not found.");
}

std::vector<Activity> ActivityContainer::getActivities() const {
    return activities;
}
