// PaymentFailedException.cpp - tiago

#include "PaymentFailedException.h"

PaymentFailedException::PaymentFailedException(const string& data) {
    this->data = data;
}

const char* PaymentFailedException::what() const noexcept {
    return data.c_str();
}
