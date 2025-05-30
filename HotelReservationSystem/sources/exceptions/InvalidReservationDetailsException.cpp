// InvalidReservationDetailsException.cpp - tiago

#include "InvalidReservationDetailsException.h"

InvalidReservationDetailsException::InvalidReservationDetailsException(const string& data) {
    this->data = data;
}

const char* InvalidReservationDetailsException::what() const noexcept {
    return data.c_str();
}
