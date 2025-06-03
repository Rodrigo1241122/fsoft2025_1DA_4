// ServiceController.h - Tiago

#ifndef CONTROLLER_SERVICECONTROLLER_H
#define CONTROLLER_SERVICECONTROLLER_H

#include "model/Service.h"
#include <vector>
#include <string>

class ServiceController {
private:
    std::vector<Service> services;

public:
    ServiceController();

    void addService(const Service& service);
    const std::vector<Service>& getAllServices() const;
    std::vector<Service> findServicesByType(const std::string& type) const;
    bool removeServiceByName(const std::string& name);
};

#endif // CONTROLLER_SERVICECONTROLLER_H
