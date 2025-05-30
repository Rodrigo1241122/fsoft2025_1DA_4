// InvalidCredentialsException.cpp - tiago

#include "InvalidCredentialsException.h"

InvalidCredentialsException::InvalidCredentialsException(const string& data) {
    this->data = data;
}

const char* InvalidCredentialsException::what() const noexcept {
    return data.c_str();
}
