// ActivityUnavailableException.cpp - tiago

#include "ActivityUnavailableException.h"

ActivityUnavailableException::ActivityUnavailableException(const string& data) {
    this->data = data;
}

const char* ActivityUnavailableException::what() const noexcept {
    return data.c_str();
}
