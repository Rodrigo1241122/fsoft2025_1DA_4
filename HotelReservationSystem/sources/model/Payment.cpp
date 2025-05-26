// Payment.cpp - tiago

#include "Payment.h"

int Payment::CODE = 1;

Payment::Payment(float amount, const Date& paymentDate) {
    this->paymentCode = CODE++;
    this->amount = amount;
    this->paymentDate = paymentDate;
}

Payment::Payment(const Payment& obj) {
    this->paymentCode = obj.paymentCode;
    this->amount = obj.amount;
    this->paymentDate = obj.paymentDate;
}

Payment::~Payment() {}

float Payment::getAmount() const {
    return amount;
}

void Payment::setAmount(float amount) {
    this->amount = amount;
}

const Date& Payment::getPaymentDate() const {
    return paymentDate;
}

void Payment::setPaymentDate(const Date& date) {
    this->paymentDate = date;
}

int Payment::getPaymentCode() const {
    return paymentCode;
}

void Payment::setPaymentCode(int code) {
    this->paymentCode = code;
}

bool Payment::operator==(const Payment& obj) const {
    return this->paymentCode == obj.paymentCode;
}

bool Payment::operator==(int code) const {
    return this->paymentCode == code;
}
