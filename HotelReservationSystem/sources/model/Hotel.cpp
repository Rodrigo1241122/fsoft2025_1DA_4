// Hotel.cpp - tiago

#include "Hotel.h"

Hotel::Hotel() {
    this->name = "Unnamed Hotel";
    this->location = "Undefined";
    this->stars = 3;
    setDataForConsistency();
}

Hotel::Hotel(const string& name, const string& location, int stars) {
    this->name = name;
    this->location = location;
    this->stars = stars;
    setDataForConsistency();
}

Hotel::Hotel(const Hotel& obj) {
    this->name = obj.name;
    this->location = obj.location;
    this->stars = obj.stars;
    this->rooms = obj.rooms;
    this->services = obj.services;
    this->activities = obj.activities;
    this->reservations = obj.reservations;
    this->comments = obj.comments;
}

Hotel::~Hotel() {}

const string& Hotel::getName() const {
    return name;
}

void Hotel::setName(const string& name) {
    this->name = name;
}

void Hotel::adicionarQuarto(const Room& quarto) {
    rooms.addRoom(quarto);
}

const string& Hotel::getLocation() const {
    return location;
}

void Hotel::setLocation(const string& location) {
    this->location = location;
}

int Hotel::getStars() const {
    return stars;
}

void Hotel::setStars(int stars) {
    this->stars = stars;
}

RoomContainer& Hotel::getRoomContainer() {
    return rooms;
}

ServiceContainer& Hotel::getServiceContainer() {
    return services;
}

ActivityContainer& Hotel::getActivityContainer() {
    return activities;
}

ReservationContainer& Hotel::getReservationContainer() {
    return reservations;
}

CommentContainer& Hotel::getCommentContainer() {
    return comments;
}

void Hotel::setDataForConsistency() {
    // Este método pode ser usado futuramente para garantir consistência ao inicializar containers ou atributos.
}
