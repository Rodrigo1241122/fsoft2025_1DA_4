//HotelController.h - Ricardo

#ifndef HOTELCONTROLLER_H
#define HOTELCONTROLLER_H

#include <string>
#include <vector>
#include "Hotel.h"

class HotelController {
public:
    HotelController();

    void addHotel(const std::string& name, const std::string& location);
    Hotel* findHotelByName(const std::string& name);
    void listHotels() const;

private:
    std::vector<Hotel> hotels;
};

#endif