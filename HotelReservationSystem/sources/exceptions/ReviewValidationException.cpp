// ReviewValidationException.cpp - tiago

#include "ReviewValidationException.h"

ReviewValidationException::ReviewValidationException(const string& data) {
    this->data = data;
}

const char* ReviewValidationException::what() const noexcept {
    return data.c_str();
}
