// ServiceContainer.cpp - Tiago

#include "model/ServiceContainer.h"
#include "exceptions/ServiceUnavailableException.h"

void ServiceContainer::addService(const Service& service) {
    services.push_back(service);
}

std::vector<Service>& ServiceContainer::getAllServices() {
    return services;
}

const std::vector<Service>& ServiceContainer::getAllServices() const {
    return services;
}

double ServiceContainer::getPriceById(int serviceId) const {
    for (const Service& s : services) {
        if (s.getId() == serviceId) {
            return s.getPrice();
        }
    }
    throw ServiceUnavailableException("Service not found.");
}


