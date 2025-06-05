// Person.cpp - Martim

#include "model/Person.h"

Person::Person() : name("") {
}

Person::Person(const string& name) : name(name) {
}

Person::Person(const Person& other) : name(other.name) {
}

Person::~Person() {
}

const string& Person::getName() const {
    return name;
}

void Person::setName(const string& name) {
    this->name = name;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        this->name = other.name;
    }
    return *this;
}

bool Person::operator==(const Person& other) const {
    return this->name == other.name;
}

bool Person::operator!=(const Person& other) const {
    return !(*this == other);
}
