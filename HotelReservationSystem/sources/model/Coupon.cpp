// Coupon.cpp - tiago

#include "model/Coupon.h"

int Coupon::CODE = 1;

Coupon::Coupon(const string& description, float discountPercentage, const Date& validUntil) {
    this->couponCode = CODE++;
    this->description = description;
    this->discountPercentage = discountPercentage;
    this->validUntil = validUntil;
}

Coupon::Coupon(const Coupon& obj) {
    this->couponCode = obj.couponCode;
    this->description = obj.description;
    this->discountPercentage = obj.discountPercentage;
    this->validUntil = obj.validUntil;
}

Coupon::~Coupon() {}

const string& Coupon::getDescription() const {
    return description;
}

void Coupon::setDescription(const string& description) {
    this->description = description;
}

float Coupon::getDiscountPercentage() const {
    return discountPercentage;
}

void Coupon::setDiscountPercentage(float discount) {
    this->discountPercentage = discount;
}

const Date& Coupon::getValidUntil() const {
    return validUntil;
}

void Coupon::setValidUntil(const Date& date) {
    this->validUntil = date;
}

int Coupon::getCouponCode() const {
    return couponCode;
}

void Coupon::setCouponCode(int code) {
    this->couponCode = code;
}

bool Coupon::operator==(const Coupon& obj) const {
    return this->couponCode == obj.couponCode;
}

bool Coupon::operator==(int code) const {
    return this->couponCode == code;
}



