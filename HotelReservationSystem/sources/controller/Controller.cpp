// controller.cpp

#include "Controller.h"
#include "Utils.h"
#include <iostream>

using namespace std;

Controller::Controller(const std::vector<Hotel>& hoteis)
    : hoteis(hoteis) {
    // Aqui podes inicializar o estado com base nos hotéis se necessário
}

void Controller::run() {
    int option;
    do {
        option = mainView.menuMain();
        switch (option) {
            case 1: runAccount(); break;
            case 2: runSearch(); break;
            case 3: runService(); break;
            case 4: runReview(); break;
            case 5: runPayment(); break;
            case 6: runActivities(); break;
            default: break;
        }
    } while (option != 0);
}

void Controller::runAccount() {
    int option;
    do {
        option = accountView.menuAccount();
        switch (option) {
            case 1: accountView.createAccount(); break;
            case 2: accountView.login(); break;
            default: break;
        }
    } while (option != 0);
}

void Controller::runSearch() {
    int option;
    do {
        option = searchView.menuSearch();
        switch (option) {
            case 1: searchView.searchAvailableRooms(); break;
            case 2: searchView.chooseRoom(); break;
            case 3: runInformation(); break;
            case 4: searchView.reserveRoom(); break;
            case 5: searchView.applyDiscountCoupon(); break;
            case 6: searchView.cancelReservation(); break;
            default: break;
        }
    } while (option != 0);
}

void Controller::runService() {
    int option;
    do {
        option = serviceView.menuService();
        switch (option) {
            case 1: serviceView.viewAvailableServices(); break;
            case 2: serviceView.requestService(); break;
            default: break;
        }
    } while (option != 0);
}

void Controller::runReview() {
    int option;
    do {
        option = reviewView.menuReview();
        switch (option) {
            case 1: reviewView.leaveStarRating(); break;
            case 2: reviewView.writeComment(); break;
            case 3: reviewView.submitReview(); break;
            default: break;
        }
    } while (option != 0);
}

void Controller::runPayment() {
    int option;
    do {
        option = paymentView.menuPayment();
        switch (option) {
            case 1: paymentView.payReservation(); break;
            case 2: paymentView.viewPaymentDetails(); break;
            default: break;
        }
    } while (option != 0);
}

void Controller::runActivities() {
    int option;
    do {
        option = activitiesView.menuActivities();
        switch (option) {
            case 1: activitiesView.viewHotelActivities(); break;
            case 2: activitiesView.registerActivity(); break;
            default: break;
        }
    } while (option != 0);
}

void Controller::runInformation() {
    int option;
    do {
        option = informationView.menuInformation();
        switch (option) {
            case 1: informationView.viewHotelInformation(); break;
            case 2: informationView.viewRoomInformation(); break;
            default: break;
        }
    } while (option != 0);
}
