// ServiceContainer.cpp - Tiago

#include "model/ServiceContainer.h"

void ServiceContainer::addService(const Service& service) {
    services.push_back(service);
}

std::vector<Service>& ServiceContainer::getAllServices() {
    return services;
}

const std::vector<Service>& ServiceContainer::getAllServices() const {
    return services;
}
