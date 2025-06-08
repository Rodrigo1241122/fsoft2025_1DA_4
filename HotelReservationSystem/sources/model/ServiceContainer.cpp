// ServiceContainer.cpp - Tiago

#include "model/ServiceContainer.h"

void ServiceContainer::addService(const Service& service) {
    services.push_back(service);
}

std::vector<Service>& ServiceContainer::getAllServices() {
    return services;
}

#include "exceptions/ServiceUnavailableException.h"

double ServiceContainer::getPriceById(int serviceId) const {
    for (const Service& s : services) {
        if (s.getId() == serviceId) {
            return s.getPrice();
        }
    }
    throw ServiceUnavailableException("Service not found.");
}


