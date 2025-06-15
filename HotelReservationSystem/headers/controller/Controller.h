#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include <string>
#include "model/Hotel.h"
#include "model/Client.h"
#include "model/Room.h"
#include "model/Reservation.h"
#include "model/Date.h"
#include "model/CommentContainer.h"

#include "views/AccountView.h"
#include "views/ActivitiesView.h"
#include "views/InformationView.h"
#include "views/MainView.h"
#include "views/PaymentView.h"
#include "views/ReviewView.h"
#include "views/RoomView.h"
#include "views/SearchView.h"
#include "views/ServiceView.h"

class Controller {
private:
    CommentContainer commentContainer;
    std::vector<Hotel> hoteis;
    std::shared_ptr<Client> currentClient = nullptr;
    std::vector<Room> selectedRooms;
    std::vector<Reservation> reservas;
    std::vector<int> reservationServices;
    std::vector<std::shared_ptr<Client>> clients;

    double additionalCharges = 0;

    // ---- Cupão e Desconto (ativos, para o pagamento atual) ----
    double discountAmount = 0.0;
    std::string discountCode;

    // Views
    MainView mainView;
    AccountView accountView;
    SearchView searchView;
    ServiceView serviceView;
    ReviewView reviewView;
    CommentContainer CommentContainer;
    PaymentView paymentView;
    ActivitiesView activitiesView;
    InformationView informationView;
    RoomView roomView;

    // Funções privadas para executar as ações de cada menu
    void runAccount();
    void runSearch();
    void runService();
    void runReview();
    void runPayment();
    void runActivities();
    void runInformation();
    void searchAvailableRooms();

public:
    // Construtor
    Controller(const std::vector<Hotel>& hoteis);

    void run();

    // ----- Gestão de Utilizador -----
    bool isLoggedIn() const;
    void setCurrentClient(std::shared_ptr<Client> client);
    std::shared_ptr<Client> getCurrentClient() const;
    const std::vector<std::shared_ptr<Client>>& getClients() const;
    void addClient(const std::shared_ptr<Client>& client);

    // ----- Gestão de Reservas -----
    void setSelectedRooms(const std::vector<Room>& rooms);
    const std::vector<Room>& getSelectedRooms() const;
    void addReservation(const Reservation& res);
    const std::vector<Reservation>& getReservations() const;
    void removeReservation(int index);
    bool hasReservation() const;

    // ----- Gestão de Descontos/Cupões -----
    void applyDiscountCoupon(const std::string& code);
    double getTotalAfterDiscount() const;
    void clearDiscount();

    // ----- Funções para coleta e cálculos -----
    Date getDateFromUser(const std::string& prompt) const;
    bool isValidReservation(const Date& checkInDate, const Date& checkOutDate) const;
    double calculateTotalPrice(const Date& checkInDate, const Date& checkOutDate, double pricePerNight) const;

    // ----- Serviços -----
    void addServiceToReservation(int serviceId);
    bool hasService(int serviceId) const;
    double getServicePriceById(int serviceId) const;
    void addToPendingAmount(double value);
    std::vector<Service> getServicesForCurrentReservationHotel() const;

    // ----- Atividades -----
    std::vector<int> reservationActivities;
    std::vector<Activity> getAvailableActivities() const;
    const std::vector<Hotel>& getHotels() const;
    std::vector<Activity> getActivitiesForCurrentReservationHotel() const;
    bool hasActivity(int activityId) const;
    void addActivityToReservation(int activityId);
    double getActivityPriceById(int activityId) const;

    // ----- Pagamentos -----
    std::vector<Reservation>& getEditableReservations();

    // Estes dois métodos **apenas delegam para o cliente atual** (NÃO GUARDAR NO CONTROLLER!)
    void setLastPaymentDate(time_t date);
    void setLastPaymentAmount(double amount);
    double getLastPaymentAmount() const;
    time_t getLastPaymentDate() const;

    bool payPending();
    double getPendingTotal() const;
    void printReceipt() const;

};

#endif // CONTROLLER_H
