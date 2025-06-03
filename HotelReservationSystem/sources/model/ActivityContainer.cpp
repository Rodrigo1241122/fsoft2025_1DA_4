// ActivityContainer.cpp - Tiago

#include "model/ActivityContainer.h"

void ActivityContainer::addActivity(const Activity& activity) {
    activities.push_back(activity);
}

std::vector<Activity>& ActivityContainer::getAllActivities() {
    return activities;
}

const std::vector<Activity>& ActivityContainer::getAllActivities() const {
    return activities;
}
