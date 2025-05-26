// Service.cpp - tiago

#include "Service.h"

int Service::CODE = 1;

Service::Service(const string& name, const string& description, float price, const Date& availableDate) {
    this->serviceCode = CODE++;
    this->name = name;
    this->description = description;
    this->price = price;
    this->availableDate = availableDate;
}

Service::Service(const Service& obj) {
    this->serviceCode = obj.serviceCode;
    this->name = obj.name;
    this->description = obj.description;
    this->price = obj.price;
    this->availableDate = obj.availableDate;
}

Service::~Service() {}

const string& Service::getName() const {
    return name;
}

void Service::setName(const string& name) {
    this->name = name;
}

const string& Service::getDescription() const {
    return description;
}

void Service::setDescription(const string& description) {
    this->description = description;
}

float Service::getPrice() const {
    return price;
}

void Service::setPrice(float price) {
    this->price = price;
}

const Date& Service::getAvailableDate() const {
    return availableDate;
}

void Service::setAvailableDate(const Date& date) {
    this->availableDate = date;
}

int Service::getServiceCode() const {
    return serviceCode;
}

void Service::setServiceCode(int code) {
    this->serviceCode = code;
}

bool Service::operator==(const Service& obj) const {
    return this->serviceCode == obj.serviceCode;
}

bool Service::operator==(int code) const {
    return this->serviceCode == code;
}
