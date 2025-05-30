// CancellationNotAllowedException.cpp - tiago

#include "CancellationNotAllowedException.h"

CancellationNotAllowedException::CancellationNotAllowedException(const string& data) {
    this->data = data;
}

const char* CancellationNotAllowedException::what() const noexcept {
    return data.c_str();
}
