#ifndef SERVICEVIEW_H
#define SERVICEVIEW_H

class Controller;

class ServiceView {
public:
    int menuService() const;
    void viewAvailableServices(const Controller& controller) const;
    void requestService(Controller& controller);
};

#endif // SERVICEVIEW_H
