// Hotel.cpp - Tiago

#include "model/Hotel.h"
#include "model/Room.h"

// ==========================
// Construtores e Destrutor
// ==========================

Hotel::Hotel() : id(0), name(""), location(""), stars(0), region("") {}

Hotel::Hotel(int id, const std::string& name, const std::string& location, int stars)
    : id(id), name(name), location(location), stars(stars), region(location)
{
    setDataForConsistency();
}

Hotel::Hotel(const std::string& name, const std::string& location, int stars)
    : id(0), name(name), location(location), stars(stars), region(location)
{
    setDataForConsistency();
}

Hotel::Hotel(int id, const std::string& name, int stars, const std::string& region,
             const std::vector<Room>& roomsVec,
             const std::vector<Service>& servicesVec,
             const std::vector<Activity>& activitiesVec)
    : id(id), name(name), stars(stars), region(region)
{
    for (const Room& r : roomsVec)
        rooms.addRoom(r);

    for (const Service& s : servicesVec)
        services.addService(s);

    for (const Activity& a : activitiesVec)
        activities.addActivity(a);

    setDataForConsistency();
}

Hotel::Hotel(const Hotel& obj)
    : id(obj.id), name(obj.name), location(obj.location), stars(obj.stars), region(obj.region),
      rooms(obj.rooms), services(obj.services), activities(obj.activities),
      reservations(obj.reservations), comments(obj.comments)
{}

Hotel::~Hotel() {}

// ==========================
// Getters e Setters básicos
// ==========================

int Hotel::getId() const {
    return id;
}

void Hotel::setId(int id) {
    this->id = id;
}

const std::string& Hotel::getName() const {
    return name;
}

void Hotel::setName(const std::string& name) {
    this->name = name;
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

std::string Hotel::getRegion() const {
    return region;
}

const std::vector<Activity>& Hotel::getActivities() const {
    return activities.getAllActivities();
}
// ==========================
// Containers e Adders
// ==========================

void Hotel::adicionarQuarto(const Room& quarto) {
    rooms.addRoom(quarto);
}

const RoomContainer& Hotel::getRoomContainer() const {
    return rooms;
}

const ServiceContainer& Hotel::getServiceContainer() const {
    return services;
}

ServiceContainer& Hotel::getServiceContainer() {
    return services;
}

const ActivityContainer& Hotel::getActivityContainer() const {
    return activities;
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

// ==========================
// Funções auxiliares
// ==========================

void Hotel::setDataForConsistency() {
    // Implementa se quiseres dados fictícios extra
}
