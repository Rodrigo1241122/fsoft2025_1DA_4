// Cancellation.cpp - tiago

#include "Cancellation.h"

int Cancellation::CODE = 1;

Cancellation::Cancellation(const string& reason, const Date& cancellationDate) {
    this->cancellationCode = CODE++;
    this->reason = reason;
    this->cancellationDate = cancellationDate;
}

Cancellation::Cancellation(const Cancellation& obj) {
    this->cancellationCode = obj.cancellationCode;
    this->reason = obj.reason;
    this->cancellationDate = obj.cancellationDate;
}

Cancellation::~Cancellation() {}

const string& Cancellation::getReason() const {
    return reason;
}

void Cancellation::setReason(const string& reason) {
    this->reason = reason;
}

const Date& Cancellation::getCancellationDate() const {
    return cancellationDate;
}

void Cancellation::setCancellationDate(const Date& date) {
    this->cancellationDate = date;
}

int Cancellation::getCancellationCode() const {
    return cancellationCode;
}

void Cancellation::setCancellationCode(int code) {
    this->cancellationCode = code;
}

bool Cancellation::operator==(const Cancellation& obj) const {
    return this->cancellationCode == obj.cancellationCode;
}

bool Cancellation::operator==(int code) const {
    return this->cancellationCode == code;
}
