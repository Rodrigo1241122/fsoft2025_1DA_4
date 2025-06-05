#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "model/Hotel.h"

#include "MainView.h"
#include "AccountView.h"
#include "SearchView.h"
#include "ServiceView.h"
#include "ReviewView.h"
#include "PaymentView.h"
#include "ActivitiesView.h"
#include "InformationView.h"
#include "RoomView.h"

class Controller {
private:
    std::vector<Hotel> hoteis;

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
    Controller(const std::vector<Hotel>& hoteis); // ← atualizado
    void run();
};

#endif // CONTROLLER_H
