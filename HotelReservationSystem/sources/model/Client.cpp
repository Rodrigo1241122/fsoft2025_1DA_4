// Client.cpp - tiago

#include "Client.h"

int Client::ID = 1;

Client::Client(const string& name, const string& email, const string& phone, const Date& birthDate) {
    this->clientID = ID++;
    this->name = name;
    this->email = email;
    this->phone = phone;
    this->birthDate = birthDate;
}

Client::Client(const Client& obj) {
    this->clientID = obj.clientID;
    this->name = obj.name;
    this->email = obj.email;
    this->phone = obj.phone;
    this->birthDate = obj.birthDate;
}

Client::~Client() {}

const string& Client::getName() const {
    return name;
}

void Client::setName(const string& name) {
    this->name = name;
}

const string& Client::getEmail() const {
    return email;
}

void Client::setEmail(const string& email) {
    this->email = email;
}

const string& Client::getPhone() const {
    return phone;
}

void Client::setPhone(const string& phone) {
    this->phone = phone;
}

const Date& Client::getBirthDate() const {
    return birthDate;
}

void Client::setBirthDate(const Date& date) {
    this->birthDate = date;
}

int Client::getClientID() const {
    return clientID;
}

void Client::setClientID(int id) {
    this->clientID = id;
}

bool Client::operator==(const Client& obj) const {
    return this->clientID == obj.clientID;
}

bool Client::operator==(int id) const {
    return this->clientID == id;
}
