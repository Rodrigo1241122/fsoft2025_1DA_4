#include "Controller.h"
#include "Utils.h"
#include <iostream>
#include "Date.h"
#include "ServiceUnavailableException.h"
#include <algorithm>
#include "ActivityUnavailableException.h"
#include "ActivitiesView.h"
#include <set>
#include "Room.h"

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
    if (currentClient) {
        option = accountView.menu_logout();
        switch (option) {
            case 1: {
                currentClient = nullptr;
                accountView.logout_confirmation();
                break;
            }
            case 0: return;
        }

    }
    else {
        option = accountView.menuAccount();
        switch (option) {
            case 1: accountView.createAccount(*this); break;
            case 2: accountView.login(*this); break;
            case 0: return;
        }
    }
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
    if (currentClient) {
        currentClient->setselectedRooms(rooms);
    }
}



const std::vector<Room>& Controller::getSelectedRooms() const {
    if (currentClient) {
        return currentClient->getSelectedRooms();
    }
    static std::vector<Room> empty;
    return empty;
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
void Controller::applyDiscount(double newTotal) {
    double totalBefore = getPendingTotal();
    if (totalBefore == 0) return;

    double ratio = newTotal / totalBefore;

    for (Reservation& r : reservas) {
        if (!r.isPaid()) {
            double adjusted = r.getTotalPrice() * ratio;
            r.setDiscountedPrice(adjusted);
        }
    }
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

void Controller::setLastPayment(double amount, const Date& date) {
    lastPaymentAmount = amount;
    lastPaymentDate = date;
}

double Controller::getLastPaymentAmount() const {
    return lastPaymentAmount;
}

time_t Controller::getLastPaymentDate() const {
    return lastPaymentDate.toTimeT();
}

// ----------- NOVA VERSÃO do pagamento -----------
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

    // Marca as reservas do cliente como pagas
    for (Reservation& r : currentClient->getReservations()) {
        if (!r.isPaid()) {
            r.markAsPaid();
        }
    }

    currentClient->setBalance(currentClient->getBalance() - totalToPay);
    std::cout << "Payment successful! " << totalToPay << " EUR deducted.\n";
    return true;
}

// ----------- NOVA VERSÃO do recibo -----------
void Controller::printReceipt() const {
    if (!isLoggedIn()) {
        std::cout << "You must be logged in to view payment details.\n";
        return;
    }
    std::cout << "\n--- Payment Receipt ---\n";
    double total = 0.0;
    for (const Reservation& r : currentClient->getReservations()) {
        if (r.isPaid()) {
            double resTotal = r.getTotalPrice();
            // Soma serviços
            for (int sid : r.getServicesIds())
                resTotal += getServicePriceById(sid);
            // Soma atividades
            for (int aid : r.getActivityIds())
                resTotal += getActivityPriceById(aid);
            std::cout << "Reservation paid: " << resTotal << " EUR\n";
            total += resTotal;
        }
    }
    std::cout << "Total paid: " << total << " EUR\n";
    std::cout << "------------------------\n";
}

void Controller::setLastPaymentDate(time_t date) {
    if (currentClient)
        currentClient->setLastPaymentDate(date);
}

void Controller::setLastPaymentAmount(double amount) {
    if (currentClient)
        currentClient->setLastPaymentAmount(amount);
}

double Controller::getPendingTotal() const {
    double total = 0.0;
    if (!isLoggedIn() || !currentClient) return total;

    for (const Reservation& r : currentClient->getReservations()) {
        if (!r.isPaid()) {
            // Preço base
            total += r.getTotalPrice();
            // Serviços
            for (int sid : r.getServicesIds())
                total += getServicePriceById(sid);
            // Atividades
            for (int aid : r.getActivityIds())
                total += getActivityPriceById(aid);
        }
    }
    return total;
}


