// Activity.cpp - tiago

#include "model/Activity.h"

int Activity::CODE = 1;

Activity::Activity(const string& title, const string& description, const Date& scheduledDate, int maxParticipants) {
    this->activityCode = CODE++;
    this->title = title;
    this->description = description;
    this->scheduledDate = scheduledDate;
    this->maxParticipants = maxParticipants;
}

Activity::Activity(const Activity& obj) {
    this->activityCode = obj.activityCode;
    this->title = obj.title;
    this->description = obj.description;
    this->scheduledDate = obj.scheduledDate;
    this->maxParticipants = obj.maxParticipants;
}

Activity::~Activity() {}

const string& Activity::getTitle() const {
    return title;
}

void Activity::setTitle(const string& title) {
    this->title = title;
}

const string& Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const string& description) {
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

bool Activity::operator==(const Activity& obj) const {
    return this->activityCode == obj.activityCode;
}

bool Activity::operator==(int code) const {
    return this->activityCode == code;
}
