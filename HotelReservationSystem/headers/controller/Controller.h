#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view/MainView.h"
#include "view/AccountView.h"
#include "view/SearchView.h"
#include "view/ServiceView.h"
#include "view/ReviewView.h"
#include "view/PaymentView.h"
#include "view/ActivitiesView.h"
#include "view/InformationView.h"
#include "view/RoomView.h"

class Controller {
private:
    MainView mainView;
    AccountView accountView;
    SearchView searchView;
    ServiceView serviceView;
    ReviewView reviewView;
    PaymentView paymentView;
    ActivitiesView activitiesView;
    InformationView informationView;
    RoomView roomView;

    void runAccount();
    void runSearch();
    void runService();
    void runReview();
    void runPayment();
    void runActivities();
    void runInformation();

public:
    Controller();
    void run();
};

#endif // CONTROLLER_H
