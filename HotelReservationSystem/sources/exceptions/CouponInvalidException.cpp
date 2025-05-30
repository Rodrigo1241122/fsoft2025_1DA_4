// CouponInvalidException.cpp - tiago

#include "CouponInvalidException.h"

CouponInvalidException::CouponInvalidException(const string& data) {
    this->data = data;
}

const char* CouponInvalidException::what() const noexcept {
    return data.c_str();
}
