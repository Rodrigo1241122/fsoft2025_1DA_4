// Hotel.h - tiago

#ifndef HEADERS_MODEL_HOTEL_H_
#define HEADERS_MODEL_HOTEL_H_

#include <string>
#include "RoomContainer.h"
#include "ServiceContainer.h"
#include "ActivityContainer.h"
#include "ReservationContainer.h"
#include "CommentContainer.h"

using namespace std;

class Hotel {
private:
    string name;
    string location;
    int stars;

    RoomContainer rooms;
    ServiceContainer services;
    ActivityContainer activities;
    ReservationContainer reservations;
    CommentContainer comments;

    void setDataForConsistency();

public:
    Hotel();
    Hotel(const string& name, const string& location, int stars);
    Hotel(const Hotel& obj);

    const string& getName() const;
    void setName(const string& name);

    const string& getLocation() const;
    void setLocation(const string& location);

    int getStars() const;
    void setStars(int stars);

    RoomContainer& getRoomContainer();
    ServiceContainer& getServiceContainer();
    ActivityContainer& getActivityContainer();
    ReservationContainer& getReservationContainer();
    CommentContainer& getCommentContainer();
};

#endif /* HEADERS_MODEL_HOTEL_H_ */
