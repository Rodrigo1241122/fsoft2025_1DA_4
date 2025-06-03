//RoomController.h - Ricardo

#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H

#include <vector>
#include <string>
#include "Room.h"

class RoomController {
public:
    RoomController();

    void addRoom(int number, const std::string& type, double price);
    Room* findRoomByNumber(int roomNumber);
    void listRooms() const;

private:
    std::vector<Room> rooms;
};

#endif