// ActivityContainer.h - Tiago

#ifndef HEADERS_MODEL_ACTIVITYCONTAINER_H_
#define HEADERS_MODEL_ACTIVITYCONTAINER_H_

#include <vector>
#include "model/Activity.h"

class ActivityContainer {
private:
    std::vector<Activity> activities;

public:
    void addActivity(const Activity& activity);
    std::vector<Activity>& getAllActivities();
    const std::vector<Activity>& getAllActivities() const;
    double getPriceById(int activityId) const;
    std::vector<Activity> getActivities() const;
};

#endif /* HEADERS_MODEL_ACTIVITYCONTAINER_H_ */
