#ifndef ROOMVIEW_H
#define ROOMVIEW_H

#include "model/Room.h"
#include <vector>

class RoomView {
public:
    void printRoom(const Room* r) const;
    void printRooms(const std::vector<Room>& rooms) const;
    void printRoomNotFound(int number) const;
};

#endif // ROOMVIEW_H
