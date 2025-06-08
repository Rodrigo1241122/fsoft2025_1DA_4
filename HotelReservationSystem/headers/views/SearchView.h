#include <iostream>
#include <vector>
#include "Room.h"
#include "Hotel.h"

#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

class Controller;
class SearchView {
public:
    int menuSearch() const;
    void chooseRoom(const std::vector<Hotel>& hotels, Controller& controller) const;
    void reserveRoom(Controller& controller) const;
    void applyDiscountCoupon(Controller& controller) const;
    void cancelReservation(Controller& controller) const;
    void searchAvailableRooms(const std::vector<Hotel>& hotels) const;
    void printAvailableRooms(const std::vector<const Room*>& rooms) const;
    void printNoAvailableRooms() const;

};

#endif // SEARCHVIEW_H
