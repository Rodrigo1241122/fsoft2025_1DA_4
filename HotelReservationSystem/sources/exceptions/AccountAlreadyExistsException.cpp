// AccountAlreadyExistsException.cpp - tiago

#include "AccountAlreadyExistsException.h"

AccountAlreadyExistsException::AccountAlreadyExistsException(const string& data) {
    this->data = data;
}

const char* AccountAlreadyExistsException::what() const noexcept {
    return data.c_str();
}
