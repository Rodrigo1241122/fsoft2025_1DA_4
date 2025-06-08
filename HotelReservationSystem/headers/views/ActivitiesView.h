// ActivityView.h
#ifndef HEADERS_VIEWS_ACTIVITIESVIEW_H_
#define HEADERS_VIEWS_ACTIVITIESVIEW_H_

#include <iostream>
class Controller; // forward declaration

class ActivitiesView {
public:
    int menuActivities() const;
    void viewHotelActivities() const;
    void registerActivity(Controller& controller);
};

#endif /* HEADERS_VIEWS_ACTIVITIESVIEW_H_ */
