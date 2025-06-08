// Hotel.cpp - Tiago

#include "model/Hotel.h"
#include "model/Room.h"

Hotel::Hotel(const std::string& name, const std::string& location, int stars) {
    this->name = name;
    this->location = location;
    this->stars = stars;
    this->region = location;
    setDataForConsistency();
}

Hotel::Hotel(const std::string& name, int stars, const std::string& region,
             const std::vector<Room>& roomsVec,
             const std::vector<Service>& servicesVec,
             const std::vector<Activity>& activitiesVec)
    : name(name), stars(stars), region(region) {

    for (const Room& r : roomsVec) {
        rooms.addRoom(r);
    }

    for (const Service& s : servicesVec) {
        services.addService(s);
    }

    for (const Activity& a : activitiesVec) {
        activities.addActivity(a);
    }

    setDataForConsistency();
}

Hotel::Hotel(const Hotel& obj) {
    this->name = obj.name;
    this->location = obj.location;
    this->stars = obj.stars;
    this->region = obj.region;
    this->rooms = obj.rooms;
    this->services = obj.services;
    this->activities = obj.activities;
    this->reservations = obj.reservations;
    this->comments = obj.comments;
}

Hotel::~Hotel() {}

const std::string& Hotel::getName() const {
    return name;
}

void Hotel::setName(const std::string& name) {
    this->name = name;
}

void Hotel::adicionarQuarto(const Room& quarto) {
    rooms.addRoom(quarto);
}

const std::string& Hotel::getLocation() const {
    return location;
}

void Hotel::setLocation(const std::string& location) {
    this->location = location;
}

int Hotel::getStars() const {
    return stars;
}

void Hotel::setStars(int stars) {
    this->stars = stars;
}

const RoomContainer& Hotel::getRoomContainer() const {
    return rooms;
}

const ServiceContainer& Hotel::getServiceContainer() const {
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

std::string Hotel::getRegion() const {
    return region;
}

void Hotel::setDataForConsistency() {
    // Dados fictícios para testes, se necessário
}

const ActivityContainer& Hotel::getActivityContainer() const {
    return activityContainer;
}