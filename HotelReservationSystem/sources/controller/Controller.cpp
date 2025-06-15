#include "Controller.h"
#include "Utils.h"
#include <iostream>
#include "Date.h"
#include "ServiceUnavailableException.h"
#include <algorithm>
#include "ActivityUnavailableException.h"
#include "ActivitiesView.h"
#include <set>

using namespace std;

// ========================
//    Construtor
// ========================
Controller::Controller(const std::vector<Hotel>& hoteis)
    : hoteis(hoteis),
      informationView(hoteis) {}

// ========================
//    Funções Main Menu
// ========================
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
        }
    } while (option != 0);
}

// ========================
//    Menu Runners
// ========================
void Controller::runAccount() {
    int option;
    do {
        option = accountView.menuAccount();
        switch (option) {
            case 1: accountView.createAccount(*this); break;
            case 2: accountView.login(*this); break;
        }
    } while (option != 0);
}

void Controller::runSearch() {
    int option;
    do {
        option = searchView.menuSearch();
        switch (option) {
            case 1: searchView.searchAvailableRooms(hoteis); break;
            case 2: searchView.chooseRoom(hoteis, *this); break;
            case 3: runInformation(); break;
            case 4: searchView.reserveRoom(*this); break;
            case 5: searchView.applyDiscountCoupon(*this); break;
            case 6: searchView.cancelReservation(*this); break;
        }
    } while (option != 0);
}

void Controller::runService() {
    int option;
    do {
        option = serviceView.menuService();
        switch (option) {
            case 1: serviceView.viewAvailableServices(hoteis); break;
            case 2: serviceView.requestService(*this); break;
        }
    } while (option != 0);
}

void Controller::runReview() {
    int option;
    int rating = 0;
    std::string comment;
    do {
        option = reviewView.menuReview();
        switch (option) {
            case 1: {
                reviewView.leaveStarRating(rating);
                if (rating < 1 || rating > 5) reviewView.incorrect_rating(); break;
            }
            case 2: reviewView.writeComment(comment); break;
            case 3: {
                if (currentClient) {
                    std::string author = currentClient->getName();
                    commentContainer.addComment(Comment(author, comment, rating,getTodayDate()));
                    reviewView.submitReview(rating, comment, commentContainer);
                } else {
                    reviewView.login_review();
                }
                    break;
            }
            case 4: reviewView.view_review(commentContainer); break;
        }
    } while (option != 0);
}

void Controller::runPayment() {
    int option;
    do {
        option = paymentView.menuPayment();
        switch (option) {
            case 1: paymentView.payReservation(*this); break;
            case 2: paymentView.printReceipt(*this); break;
        }
    } while (option != 0);
}

void Controller::runActivities() {
    int option;
    do {
        option = activitiesView.menuActivities();
        switch (option) {
            case 1: activitiesView.viewHotelActivities(*this); break;
            case 2: activitiesView.registerActivity(*this); break;
        }
    } while (option != 0);
}

void Controller::runInformation() {
    int option;
    do {
        option = informationView.menuInformation();
        switch (option) {
            case 1: informationView.viewHotelInfo(); break;
            case 2: informationView.viewRoomInformation(); break;
        }
    } while (option != 0);
}

// ========================
//    Login & Client Management
// ========================
bool Controller::isLoggedIn() const {
    return currentClient != nullptr;
}

void Controller::setCurrentClient(std::shared_ptr<Client> client) {
    currentClient = client;
}

std::shared_ptr<Client> Controller::getCurrentClient() const {
    return currentClient;
}

const std::vector<std::shared_ptr<Client>>& Controller::getClients() const {
    return clients;
}

void Controller::addClient(const std::shared_ptr<Client>& client) {
    clients.push_back(client);
}

// ========================
//    Reservations Management
// ========================
void Controller::setSelectedRooms(const std::vector<Room>& rooms) {
    selectedRooms = rooms;
}

const std::vector<Room>& Controller::getSelectedRooms() const {
    return selectedRooms;
}

void Controller::addReservation(const Reservation& res) {
    reservas.push_back(res);
    if (isLoggedIn()) {
        currentClient->addReservation(res);
    }
}

const std::vector<Reservation>& Controller::getReservations() const {
    return reservas;
}

void Controller::removeReservation(int index) {
    if (index >= 0 && index < (int)reservas.size()) {
        reservas.erase(reservas.begin() + index);
    }
}

const std::vector<Hotel>& Controller::getHotels() const {
    return hoteis;
}

bool Controller::hasReservation() const {
    if (!isLoggedIn()) return false;
    return !currentClient->getReservations().empty();
}
// ========================
//    Financial Functions
// ========================
void Controller::applyDiscountCoupon(const std::string& code) {
    double total = getPendingTotal();
    discountCode = code;
    if (code == "20") discountAmount = 20.0;
    else if (code == "20porcento") discountAmount = total * 0.2;
    else if (code == "100") discountAmount = 100.0;
    else if (code == "100porcento") discountAmount = total;
    else discountAmount = 0.0;

    if (discountAmount > total) discountAmount = total;
}

double Controller::getTotalAfterDiscount() const {
    double total = getPendingTotal();
    double final = total - discountAmount;
    return final < 0 ? 0 : final;
}

void Controller::clearDiscount() {
    discountAmount = 0.0;
    discountCode.clear();
}

// ========================
//    User Input & Calculation Helpers
// ========================
Date Controller::getDateFromUser(const std::string& prompt) const {
    int day, month, year;
    std::cout << prompt;
    std::cin >> day >> month >> year;
    Date userDate(day, month, year);
    return userDate;
}

bool Controller::isValidReservation(const Date& checkInDate, const Date& checkOutDate) const {
    Date today = getTodayDate();
    if (checkInDate.isBefore(today)) {
        std::cout << "Check-in date cannot be in the past.\n";
        return false;
    }
    if (checkInDate.isAfter(checkOutDate)) {
        std::cout << "Check-out date cannot be before check-in date.\n";
        return false;
    }
    return true;
}

double Controller::calculateTotalPrice(const Date& checkInDate, const Date& checkOutDate, double pricePerNight) const {
    int numNights = checkInDate.daysBetween(checkOutDate);
    return numNights * pricePerNight;
}

// ========================
//    Service Functions
// ========================
void Controller::addServiceToReservation(int serviceId) {
    reservationServices.push_back(serviceId);
}

bool Controller::hasService(int serviceId) const {
    return std::find(reservationServices.begin(), reservationServices.end(), serviceId) != reservationServices.end();
}

double Controller::getServicePriceById(int serviceId) const {
    for (const Hotel& h : hoteis) {
        try {
            return h.getServiceContainer().getPriceById(serviceId);
        } catch (...) {
        }
    }
    throw ServiceUnavailableException("Service not found.");
}

void Controller::addToPendingAmount(double value) {
    additionalCharges += value;
}

std::vector<Service> Controller::getServicesForCurrentReservationHotel() const {
    if (!currentClient || currentClient->getReservations().empty()) {
        return {};
    }
    int hotelId = currentClient->getReservations().back().getHotelId();
    for (const auto& hotel : hoteis) {
        if (hotel.getId() == hotelId) {
            return hotel.getServiceContainer().getAllServices();
        }
    }
    return {};
}

// ========================
//    Activity Functions
// ========================
bool Controller::hasActivity(int activityId) const {
    if (!hasReservation()) return false;

    return currentClient->getReservations().back().hasActivity(activityId);
}

double Controller::getActivityPriceById(int activityId) const {
    if (!hasReservation()) return 0.0;

    int hotelId = currentClient->getReservations().back().getHotelId();

    for (const auto& hotel : hoteis) {
        if (hotel.getId() == hotelId) {
            const auto& activities = hotel.getActivityContainer().getActivities();
            for (const auto& activity : activities) {
                if (activity.getId() == activityId)
                    return activity.getPrice();
            }
        }
    }

    throw ActivityUnavailableException("Activity not found.");
}

void Controller::addActivityToReservation(int activityId) {
    if (!hasReservation()) return;

    currentClient->getReservations().back().addActivity(activityId);
}

std::vector<Activity> Controller::getAvailableActivities() const {
    std::vector<Activity> activities;
    std::set<int> seenIds; // evitar duplicados (caso os hotéis tenham atividades com o mesmo ID)
    for (const Hotel& h : hoteis) {
        for (const Activity& a : h.getActivityContainer().getActivities()) {
            if (seenIds.insert(a.getId()).second) { // só adiciona se não foi já adicionado
                activities.push_back(a);
            }
        }
    }
    return activities;
}

std::vector<Activity> Controller::getActivitiesForCurrentReservationHotel() const {
    if (!currentClient || currentClient->getReservations().empty()) {
        return {};
    }

    int hotelId = currentClient->getReservations().back().getHotelId();

    for (const auto& hotel : hoteis) {
        if (hotel.getId() == hotelId) {
            return hotel.getActivityContainer().getActivities();
        }
    }

    return {};
}

// ========================
//    Payment Functions
// ========================

std::vector<Reservation>& Controller::getEditableReservations() {
    return reservas;
}

void Controller::setLastPaymentAmount(double amount) {
    if (currentClient)
        currentClient->setLastPaymentAmount(amount);
}

void Controller::setLastPaymentDate(time_t date) {
    if (currentClient)
        currentClient->setLastPaymentDate(date);
}

double Controller::getLastPaymentAmount() const {
    return currentClient ? currentClient->getLastPaymentAmount() : 0.0;
}

time_t Controller::getLastPaymentDate() const {
    return currentClient ? currentClient->getLastPaymentDate() : 0;
}

bool Controller::payPending() {
    double totalToPay = getPendingTotal();
    
    if (!isLoggedIn()) {
        std::cout << "You must be logged in to pay.\n";
        return false;
    }

    if (currentClient->getBalance() < totalToPay) {
        std::cout << "Insufficient balance. Total: " << totalToPay << " EUR | Balance: " << currentClient->getBalance() << " EUR\n";
        return false;
    }

    for (Reservation& r : currentClient->getReservations()) {
        if (!r.isPaid()) {
            r.markAsPaid();
        }
    }

    currentClient->setBalance(currentClient->getBalance() - totalToPay);

    setLastPaymentAmount(totalToPay - discountAmount);
    setLastPaymentDate(time(nullptr));

    return true;
}

void Controller::printReceipt() const {
    if (!isLoggedIn()) {
        std::cout << "You must be logged in to view payment details.\n";
        return;
    }

    double lastPayment = getLastPaymentAmount();
    if (lastPayment <= 0.0) {
        std::cout << "No payments have been made yet.\n";
        return;
    }

    time_t paymentDate = getLastPaymentDate();

    std::cout << "\n--- Payment Receipt ---\n";
    double total = 0.0;
    for (const Reservation& r : currentClient->getReservations()) {
        if (r.isPaid()) {
            double resTotal = r.getTotalPrice();
            for (int sid : r.getServicesIds())
                resTotal += getServicePriceById(sid);
            for (int aid : r.getActivityIds())
                resTotal += getActivityPriceById(aid);
            std::cout << "Reservation paid: " << resTotal << " EUR\n";
            total += resTotal;
        }
    }
    std::cout << "Total paid: " << total << " EUR\n";
    std::cout << "Last payment: " << lastPayment << " EUR\n";
    std::cout << "Payment date: " << ctime(&paymentDate);
    std::cout << "------------------------\n";
}

double Controller::getPendingTotal() const {
    double total = 0.0;
    if (!isLoggedIn() || !currentClient) return total;

    for (const Reservation& r : currentClient->getReservations()) {
        if (!r.isPaid()) {
            total += r.getTotalPrice();
            for (int sid : r.getServicesIds())
                total += getServicePriceById(sid);
            for (int aid : r.getActivityIds())
                total += getActivityPriceById(aid);
        }
    }
    return total;
}
