// ActivitIESView.cpp - Tiago

#include "ActivitiesView.h"
#include <iostream>
#include <limits>
#include "exceptions/ActivityUnavailableException.h"
#include "Controller.h"

using namespace std;

int ActivitiesView::menuActivities() const {
    int option;
    cout << "\n=== Activities Menu ===\n";
    cout << "1. View Activities\n";
    cout << "2. Register Activity\n";
    cout << "0. Back\n";
    cout << "Option: ";
    cin >> option;
    return option;
}

void ActivitiesView::viewHotelActivities() const {
    cout << "\nAvailable Activities:\n";
    cout << "1. Spa - Relaxing full-body massage. (Price: 50 EUR)\n";
    cout << "2. Gym Access - Unlimited gym use. (Price: 20 EUR)\n";
    cout << "3. Pool - All-day pool access. (Price: 15 EUR)\n";
    cout << "4. Guided Tour - Explore the city with a guide. (Price: 30 EUR)\n";
    cout << "0. Back\n";
}

void ActivitiesView::registerActivity(Controller& controller) {
    if (!controller.isLoggedIn()) {
        cout << "You must be logged in to register an activity.\n";
        return;
    }

    if (controller.getReservations().empty()) {
        cout << "You must have at least one reservation to register an activity.\n";
        return;
    }

    viewHotelActivities();

    int id;
    cout << "\nEnter the ID of the activity you want to register: ";
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.\n";
        return;
    }

    if (controller.hasActivity(id)) {
        cout << "You have already registered for this activity.\n";
        return;
    }

    try {
        double price = controller.getActivityPriceById(id);
        controller.addActivityToReservation(id);
        controller.addToPendingAmount(price);
        cout << "Activity registered! Price: " << price << " EUR\n";
    } catch (const ActivityUnavailableException& e) {
        cout << "Error: " << e.what() << "\n";
    }
}
