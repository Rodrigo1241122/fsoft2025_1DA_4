// RoomNotAvailableException.cpp - tiago

#include "RoomNotAvailableException.h"

RoomNotAvailableException::RoomNotAvailableException(const string& data) {
    this->data = data;
}

const char* RoomNotAvailableException::what() const noexcept {
    return data.c_str();
}
