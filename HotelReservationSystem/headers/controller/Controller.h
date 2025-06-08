#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include "model/Hotel.h"
#include "model/Client.h"
#include "model/Room.h"
#include "model/Reservation.h"
#include "model/Date.h"

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
    std::vector<Hotel> hoteis;
    std::shared_ptr<Client> currentClient = nullptr;
    std::vector<Room> selectedRooms;
    std::vector<Reservation> reservas;
    std::vector<int> reservationServices;
    
    double additionalCharges = 0;
    MainView mainView;
    AccountView accountView;
    SearchView searchView;
    ServiceView serviceView;
    ReviewView reviewView;
    PaymentView paymentView;
    ActivitiesView activitiesView;
    InformationView informationView;
    RoomView roomView;

    // Métodos privados para executar as ações de cada menu
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
    
    // Método para rodar o sistema
    void run();

    // Métodos de login e manipulação do cliente
    bool isLoggedIn() const;
    void setCurrentClient(std::shared_ptr<Client> client);
    std::shared_ptr<Client> getCurrentClient() const;

    // Métodos para manipulação de reservas
    void setSelectedRooms(const std::vector<Room>& rooms);
    const std::vector<Room>& getSelectedRooms() const;
    void addReservation(const Reservation& res);
    const std::vector<Reservation>& getReservations() const;
    void removeReservation(int index);

    // Métodos financeiros
    double getPendingTotal() const;
    void applyDiscount(double newTotal);

    // Métodos para coletar dados do usuário e realizar cálculos
    Date getDateFromUser(const std::string& prompt) const;
    bool isValidReservation(const Date& checkInDate, const Date& checkOutDate) const;  // Valida as datas
    double calculateTotalPrice(const Date& checkInDate, const Date& checkOutDate, double pricePerNight) const;  // Calcula o preço total

    // Métodos Serviços
    void addServiceToReservation(int serviceId);
    bool hasService(int serviceId) const;
    double getServicePriceById(int serviceId) const;
    void addToPendingAmount(double value);

    // Métodos Atividades
    bool hasActivity(int activityId) const;
    std::vector<int> reservationActivities;
    double getActivityPriceById(int activityId) const;
    void addActivityToReservation(int activityId);

    // --- Payment Related Methods ---
    double getAdditionalCharges() const;  // Declaração correta para obter o valor das cobranças adicionais
    void clearAdditionalCharges();  // Declaração para limpar as cobranças adicionais

    std::vector<Reservation>& getEditableReservations();  // Apenas uma declaração desta função
    void setLastPayment(double amount, const Date& date);
    double getLastPaymentAmount() const;
    time_t getLastPaymentDate() const;
    bool payPending();
    void printReceipt() const;
    void setLastPaymentDate(time_t date);
    void setLastPaymentAmount(double amount);

    // --- Payment Related Attributes ---
    double lastPaymentAmount = 0;
    Date lastPaymentDate;
};

#endif // CONTROLLER_H
