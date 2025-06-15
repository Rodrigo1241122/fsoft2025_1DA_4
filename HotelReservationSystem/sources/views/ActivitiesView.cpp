// ActivitIESView.cpp - Tiago

#include "ActivitiesView.h"
#include <iostream>
#include <limits>
#include "exceptions/ActivityUnavailableException.h"
#include "Controller.h"
#include <algorithm>

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

void ActivitiesView::viewHotelActivities(Controller& controller) const {
    std::cout << "\n=== Available Activities ===\n";
   const auto& hoteis = controller.getHotels();
    for (const Hotel& hotel : hoteis) {
        const auto& activities = hotel.getActivityContainer().getAllActivities();
        if (!activities.empty()) {
            std::cout << "Hotel: " << hotel.getName() << "\n";
            for (const auto& Activity : activities) {
                std::cout << "  ID: " << Activity.getId()
                          << " - " << Activity.getTitle()
                          << " - " << Activity.getDescription()
                          << " (Price: " << Activity.getPrice() << " EUR)\n";
            }
        }
    }
    std::cout << "0. Back\n";
}

void ActivitiesView::registerActivity(Controller& controller) {
    if (!controller.isLoggedIn()) {
        std::cout << "You must be logged in to register for an activity.\n";
        return;
    }

    if (controller.getReservations().empty()) {
        std::cout << "You must have at least one reservation to register for an activity.\n";
        return;
    }

    std::vector<Activity> availableActivities = controller.getActivitiesForCurrentReservationHotel();

    if (availableActivities.empty()) {
        std::cout << "No available activities for your reservation's hotel.\n";
        return;
    }

    std::cout << "\n=== Available Activities ===\n";
    for (const auto& activity : availableActivities) {
        std::cout << "  ID: " << activity.getId()
                  << " - " << activity.getTitle()
                  << " - " << activity.getDescription()
                  << " (Price: " << activity.getPrice() << " EUR)\n";
    }
    std::cout << "0. Back\n";

    int id;
    std::cout << "\nEnter the ID of the activity you want to register: ";
    std::cin >> id;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.\n";
        return;
    }
    if (id == 0) return;

    auto it = std::find_if(
        availableActivities.begin(),
        availableActivities.end(),
        [id](const Activity& a) { return a.getId() == id; });

    if (it == availableActivities.end()) {
        std::cout << "Invalid activity ID for your hotel.\n";
        return;
    }

    if (controller.hasActivity(id)) {
        std::cout << "You have already registered this activity.\n";
        return;
    }

    try {
        double price = controller.getActivityPriceById(id);
        controller.addActivityToReservation(id);
        controller.addToPendingAmount(price);
        std::cout << "Activity registered successfully! Price: " << price << " EUR\n";
    } catch (const ActivityUnavailableException& e) {
        std::cout << "Error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

