// RoomContainer.h
#ifndef HEADERS_MODEL_ROOMCONTAINER_H_
#define HEADERS_MODEL_ROOMCONTAINER_H_

#include <vector>
#include "model/Room.h" 
class RoomContainer {
private:
    std::vector<Room> rooms = {};

public:
    void addRoom(const Room& room);
    const std::vector<Room>& getAll() const;
    std::vector<Room>& getAllRooms();
    const std::vector<Room>& getAllRooms() const;
    int size() const {
        return rooms.size();
    }
};

#endif 