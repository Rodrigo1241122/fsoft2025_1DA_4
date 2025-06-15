// Activity.cpp - Tiago

#include "model/Activity.h"

int Activity::CODE = 1;

Activity::Activity(const std::string& title, const std::string& description, const Date& scheduledDate, int maxParticipants) {
    this->activityCode = CODE++;
    this->title = title;
    this->description = description;
    this->scheduledDate = scheduledDate;
    this->maxParticipants = maxParticipants;
    this->id = 0;
    this->price = 0.0f;
}

Activity::Activity(const Activity& obj) {
    this->activityCode = obj.activityCode;
    this->title = obj.title;
    this->description = obj.description;
    this->scheduledDate = obj.scheduledDate;
    this->maxParticipants = obj.maxParticipants;
    this->id = obj.id;
    this->price = obj.price;
}

Activity::Activity(int id, const std::string& title, const std::string& description, float price)
    : id(id), title(title), description(description), price(price) {
    this->activityCode = CODE++;
    this->scheduledDate = Date(); // valor por omissão
    this->maxParticipants = 0;
}

Activity::~Activity() {}

const std::string& Activity::getTitle() const {
    return title;
}

void Activity::setTitle(const std::string& title) {
    this->title = title;
}

const std::string& Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string& description) {
    this->description = description;
}

const Date& Activity::getScheduledDate() const {
    return scheduledDate;
}

void Activity::setScheduledDate(const Date& date) {
    this->scheduledDate = date;
}

int Activity::getMaxParticipants() const {
    return maxParticipants;
}

void Activity::setMaxParticipants(int max) {
    this->maxParticipants = max;
}

int Activity::getActivityCode() const {
    return activityCode;
}

void Activity::setActivityCode(int code) {
    this->activityCode = code;
}

int Activity::getId() const {
    return id;
}

float Activity::getPrice() const {
    return price;
}

bool Activity::operator==(const Activity& obj) const {
    return this->activityCode == obj.activityCode;
}

bool Activity::operator==(int code) const {
    return this->activityCode == code;
}
