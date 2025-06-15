#include "model/Service.h"

Service::Service(int id, const std::string& name, const std::string& description, float price)
    : id(id), name(name), description(description), price(price) {}

Service::Service(const Service& obj)
    : id(obj.id), name(obj.name), description(obj.description), price(obj.price), availableDate(obj.availableDate) {}

Service::Service(const std::string& name, const std::string& description, float price, const Date& availableDate)
    : id(0), name(name), description(description), price(price), availableDate(availableDate) {}

Service::~Service() {}

const std::string& Service::getName() const { return name; }
void Service::setName(const std::string& name) { this->name = name; }
const std::string& Service::getDescription() const { return description; }
void Service::setDescription(const std::string& description) { this->description = description; }
float Service::getPrice() const { return price; }
void Service::setPrice(float price) { this->price = price; }
const Date& Service::getAvailableDate() const { return availableDate; }
void Service::setAvailableDate(const Date& date) { this->availableDate = date; }

// === O ÚNICO MÉTODO DE ID QUE PRECISAS ===
int Service::getId() const { return id; }

bool Service::operator==(const Service& obj) const {
    return this->id == obj.id;
}
bool Service::operator==(int code) const {
    return this->id == code;
}
