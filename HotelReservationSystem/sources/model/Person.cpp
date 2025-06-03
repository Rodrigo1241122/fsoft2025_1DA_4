// Person.cpp - Martim

#include "model/Person.h"

// Construtor padrão
Person::Person() : name("") {
}

// Construtor com parâmetro
Person::Person(const string& name) : name(name) {
}

// Construtor de cópia
Person::Person(const Person& other) : name(other.name) {
}

// Destrutor virtual
Person::~Person() {
}

// Getter para name
const string& Person::getName() const {
    return name;
}

// Setter para name
void Person::setName(const string& name) {
    this->name = name;
}

// Operador de atribuição
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        this->name = other.name;
    }
    return *this;
}

// Operador de igualdade
bool Person::operator==(const Person& other) const {
    return this->name == other.name;
}

// Operador de desigualdade
bool Person::operator!=(const Person& other) const {
    return !(*this == other);
}
