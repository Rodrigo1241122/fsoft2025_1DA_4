#include "model/Client.h"

int Client::ID = 1;

Client::Client(const std::string& name, const std::string& email)
    : name(name), email(email), balance(1000.0f), lastPaymentDate(0), lastPaymentAmount(0.0) {
    this->clientID = ID++;
}

Client::Client(const Client& obj) {
    this->clientID = obj.clientID;
    this->name = obj.name;
    this->email = obj.email;
    this->balance = obj.balance;
    this->lastPaymentDate = obj.lastPaymentDate;
    this->lastPaymentAmount = obj.lastPaymentAmount;
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

void Client::setBalance(float value) {
    this->balance = value;
}

float Client::getBalance() const {
    return balance;
}

void Client::addBalance(double amount) {
    balance += amount;  // Adiciona o valor ao saldo
}

void Client::setLastPaymentDate(time_t date) {
    lastPaymentDate = date;
}

time_t Client::getLastPaymentDate() const {
    return lastPaymentDate;
}

void Client::setLastPaymentAmount(double amount) {
    lastPaymentAmount = amount;
}

double Client::getLastPaymentAmount() const {
    return lastPaymentAmount;
}
