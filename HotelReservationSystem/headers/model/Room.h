// Room.h - Tiago

#ifndef HEADERS_MODEL_ROOM_H_
#define HEADERS_MODEL_ROOM_H_

#include "data/RoomType.h"

class Room {
private:
    int number;
    double pricePerNight;
    RoomType type;

public:
    Room();
    Room(int number, double pricePerNight, RoomType type);
    Room(const Room& other);

    int getNumber() const;
    void setNumber(int number);

    double getPricePerNight() const;
    void setPricePerNight(double price);

    RoomType getType() const;
    void setType(RoomType type);

    bool operator==(const Room& other) const;
};

#endif /* HEADERS_MODEL_ROOM_H_ */
