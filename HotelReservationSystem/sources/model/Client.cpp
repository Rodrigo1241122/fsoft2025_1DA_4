#include "model/Client.h"

// =============================
//    Inicialização do ID estático
// =============================
int Client::ID = 1;

// =============================
//    Construtores e destrutor
// =============================
Client::Client(const std::string& name, const std::string& email, const std::string& password, double balance)
    : name(name), email(email), password(password), balance(balance) {
    this->clientID = ID++;
}

Client::Client(const Client& obj) {
    this->clientID = obj.clientID;
    this->name = obj.name;
    this->email = obj.email;
    this->password = obj.password;
    this->balance = obj.balance;
    this->lastPaymentDate = obj.lastPaymentDate;
    this->lastPaymentAmount = obj.lastPaymentAmount;
}

Client::~Client() {}

// =============================
//    Getters e setters principais
// =============================
const std::string& Client::getName() const {
    return name;
}

void Client::setName(const std::string& name) {
    this->name = name;
}

const std::string& Client::getEmail() const {
    return email;
}

void Client::setEmail(const std::string& email) {
    this->email = email;
}

const std::string& Client::getPassword() const {
    return password;
}

void Client::setPassword(const std::string& password) {
    this->password = password;
}

int Client::getClientID() const {
    return clientID;
}

void Client::setClientID(int id) {
    this->clientID = id;
}

// =============================
//    Operadores de comparação
// =============================
bool Client::operator==(const Client& obj) const {
    return this->clientID == obj.clientID;
}

bool Client::operator==(int id) const {
    return this->clientID == id;
}

// =============================
//    Gestão de saldo
// =============================
void Client::setBalance(float value) {
    this->balance = value;
}

float Client::getBalance() const {
    return balance;
}

void Client::addBalance(double amount) {
    balance += amount;
}

// =============================
//    Gestão de pagamentos
// =============================
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

// =============================
//    Gestão de reservas
// =============================

const std::vector<Reservation>& Client::getReservations() const {
    return reservations;
}

std::vector<Reservation>& Client::getReservations() {
    return reservations;
}

void Client::addReservation(const Reservation& reservation) {
    reservations.push_back(reservation);
}
