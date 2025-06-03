//Room.h - Ricardo
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "RoomType.h"  // ← IMPORTANTE

class Room {
private:
    int number;
    double pricePerNight;
    RoomType type;  // ← ENUM INTEGRADO

public:
    Room();
    Room(int number, double price, RoomType type);
    int getNumber() const;
    double getPricePerNight() const;
    RoomType getType() const;

    void setPricePerNight(double price);
    void setType(RoomType type);
};

#endif // ROOM_H