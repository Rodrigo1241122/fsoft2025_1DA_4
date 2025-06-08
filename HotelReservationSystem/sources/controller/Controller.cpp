#include "Controller.h"
#include "Utils.h"
#include <iostream>
#include "Date.h"
#include "ServiceUnavailableException.h"
#include <algorithm>
#include "ActivityUnavailableException.h"
#include "ActivitiesView.h"

using namespace std;

Controller::Controller(const std::vector<Hotel>& hoteis)
    : hoteis(hoteis),
      informationView(hoteis) {}

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

void Controller::runAccount() {
    int option;
    do {
        option = accountView.menuAccount();
        switch (option) {
            case 1: accountView.createAccount(); break;
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
            case 6: 
            searchView.cancelReservation(*this); 
            break;
        }
    } while (option != 0);
}

void Controller::runService() {
    int option;
    do {
        option = serviceView.menuService();
        switch (option) {
            case 1: serviceView.viewAvailableServices(); break;
            case 2: serviceView.requestService(*this); break;
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
            case 1: activitiesView.viewHotelActivities(); break;
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

bool Controller::isLoggedIn() const {
    return currentClient != nullptr;
}

void Controller::setCurrentClient(std::shared_ptr<Client> client) {
    currentClient = client;
}

std::shared_ptr<Client> Controller::getCurrentClient() const {
    return currentClient;
}

void Controller::setSelectedRooms(const std::vector<Room>& rooms) {
    selectedRooms = rooms;
}

const std::vector<Room>& Controller::getSelectedRooms() const {
    return selectedRooms;
}

void Controller::addReservation(const Reservation& res) {
    reservas.push_back(res);
}

const std::vector<Reservation>& Controller::getReservations() const {
    return reservas;
}

double Controller::getPendingTotal() const {
    double total = 0;
    for (const Reservation& r : reservas) {
        if (!r.isPaid()) {
            total += r.getTotalPrice();
        }
    }
    return total;
}

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

void Controller::removeReservation(int index) {
    if (index >= 0 && index < (int)reservas.size()) {
        reservas.erase(reservas.begin() + index);
    }
}

Date Controller::getDateFromUser(const std::string& prompt) const {
    int day, month, year;
    std::cout << prompt;  // Exibe a solicitação para o usuário
    std::cin >> day >> month >> year;  // Lê a entrada de data

    // Criação e retorno de um objeto Date com os valores inseridos
    Date userDate(day, month, year);
    return userDate;
}

bool Controller::isValidReservation(const Date& checkInDate, const Date& checkOutDate) const {
    Date today = getTodayDate();  // Método que retorna a data atual

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
    int numNights = checkInDate.daysBetween(checkOutDate);  // Método que calcula o número de noites
    return numNights * pricePerNight;
}

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

bool Controller::hasActivity(int activityId) const {
    return std::find(reservationActivities.begin(), reservationActivities.end(), activityId) != reservationActivities.end();
}

double Controller::getActivityPriceById(int activityId) const {
    for (const Hotel& h : hoteis) {
        try {
            return h.getActivityContainer().getPriceById(activityId);
        } catch (...) {
        }
    }
    throw ActivityUnavailableException("Activity not found.");
}

void Controller::addActivityToReservation(int activityId) {
    reservationActivities.push_back(activityId);
}

double Controller::getAdditionalCharges() const {
    return additionalCharges;
}

void Controller::clearAdditionalCharges() {
    additionalCharges = 0;
}

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
    return lastPaymentDate.toTimeT();  // Usando o método toTimeT() para converter Date para time_t
}

bool Controller::payPending() {
    double totalToPay = 0;

    for (Reservation& r : reservas) {
        if (!r.isPaid()) {
            totalToPay += r.getTotalPrice();
        }
    }
    totalToPay += additionalCharges;

    if (!isLoggedIn()) {
        std::cout << "You must be logged in to pay.\n";
        return false;
    }

    if (currentClient->getBalance() < totalToPay) {
        std::cout << "Insufficient balance. Total: " << totalToPay << " EUR | Balance: " << currentClient->getBalance() << " EUR\n";
        return false;
    }

    for (Reservation& r : reservas) {
        if (!r.isPaid()) {
            r.markAsPaid();
        }
    }

    currentClient->setBalance(currentClient->getBalance() - totalToPay);
    additionalCharges = 0;

    std::cout << "Payment successful! " << totalToPay << " EUR deducted.\n";
    return true;
}

void Controller::printReceipt() const {
    if (!isLoggedIn()) {
        std::cout << "You must be logged in to view payment details.\n";
        return;
    }

    std::cout << "\n--- Payment Receipt ---\n";
    for (const Reservation& r : reservas) {
        if (r.isPaid()) {
            std::cout << "Reservation paid: " << r.getTotalPrice() << " EUR\n";
        }
    }
    if (additionalCharges == 0) {
        std::cout << "All extra charges have been paid.\n";
    } else {
        std::cout << "Unpaid additional charges: " << additionalCharges << " EUR\n";
    }
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
