#ifndef INFORMATIONVIEW_H
#define INFORMATIONVIEW_H

#include "../model/Hotel.h"
#include <vector>

class InformationView {
private:
    const std::vector<Hotel>& hotels;

public:
    InformationView(const std::vector<Hotel>& hotels);
    
    int menuInformation() const;
    void viewInfo() const;
    void viewRoomInformation() const;
    void viewHotelInfo() const;
};

#endif // INFORMATIONVIEW_H
