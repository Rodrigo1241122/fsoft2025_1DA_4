// ServiceUnavailableException.cpp - tiago

#include "ServiceUnavailableException.h"

ServiceUnavailableException::ServiceUnavailableException(const string& data) {
    this->data = data;
}

const char* ServiceUnavailableException::what() const noexcept {
    return data.c_str();
}
