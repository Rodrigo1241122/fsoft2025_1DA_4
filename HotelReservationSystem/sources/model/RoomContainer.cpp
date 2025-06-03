// RoomContainer.cpp - Tiago

#include "model/RoomContainer.h"

void RoomContainer::addRoom(const Room& room) {
    rooms.push_back(room);
}

std::vector<Room>& RoomContainer::getAllRooms() {
    return rooms;
}

const std::vector<Room>& RoomContainer::getAllRooms() const {
    return rooms;
}
