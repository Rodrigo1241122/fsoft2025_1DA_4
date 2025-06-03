// ServiceController.cpp - Tiago

#include "controller/ServiceController.h"

ServiceController::ServiceController() {}

std::vector<Service> ServiceController::viewAvailableServices(const Hotel& hotel) const {
    return hotel.getServiceContainer().getAllServices();
}

bool ServiceController::addServiceToReservation(std::shared_ptr<Reservation> reserva, const Service& service) {
    if (!reserva) return false;
    reserva->addService(service);  // Reservation deve ter este método
    return true;
}

bool ServiceController::removeServiceFromReservation(std::shared_ptr<Reservation> reserva, const std::string& serviceName) {
    if (!reserva) return false;
    return reserva->removeServiceByName(serviceName);  // Reservation deve suportar isto
}
