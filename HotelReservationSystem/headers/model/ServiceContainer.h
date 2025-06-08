// ServiceContainer.h - Tiago

#ifndef HEADERS_MODEL_SERVICECONTAINER_H_
#define HEADERS_MODEL_SERVICECONTAINER_H_

#include <vector>
#include "Service.h"

class ServiceContainer {
private:
    std::vector<Service> services;

public:
    void addService(const Service& service);
    
    std::vector<Service>& getAllServices();
    const std::vector<Service>& getAllServices() const;
    double getPriceById(int serviceId) const;
};

#endif /* HEADERS_MODEL_SERVICECONTAINER_H_ */
