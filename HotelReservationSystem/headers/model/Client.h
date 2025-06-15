#ifndef HEADERS_MODEL_CLIENT_H_
#define HEADERS_MODEL_CLIENT_H_

#include <string>
#include <ctime>
#include <vector>
#include "model/Date.h"
#include "model/Reservation.h"
#include "Room.h"

using namespace std;


class Client {
private:
    vector<Room> selectedrooms;
    static int ID;
    int clientID;
    string name;
    string email;
    string password;
    double balance;
    time_t lastPaymentDate;
    double lastPaymentAmount;

    std::vector<Reservation> reservations;

public:
    void setselectedRooms(const vector<Room>& rooms) {
        selectedrooms = rooms;
    }

    const vector<Room>& getSelectedRooms() const {
        return selectedrooms;
    }

    Client(const string& name, const string& email, const string& password, double balance);
    Client(const Client& obj);
    ~Client();

    // ==== Getters e setters principais ====
    const string& getName() const;
    void setName(const string& name);

    const string& getEmail() const;
    void setEmail(const string& email);

    const string& getPassword() const;
    void setPassword(const string& password);

    int getClientID() const;
    void setClientID(int id);

    // ==== Operadores de comparação ====
    bool operator==(const Client& obj) const;
    bool operator==(int id) const;

    // ==== Gestão de saldo ====
    void setBalance(float value);
    float getBalance() const;
    void addBalance(double amount);

    // ==== Gestão de pagamentos ====
    void setLastPaymentDate(time_t date);
    time_t getLastPaymentDate() const;
    void setLastPaymentAmount(double amount);
    double getLastPaymentAmount() const;

    // ==== Gestão de reservas ====
    const std::vector<Reservation>& getReservations() const;
    std::vector<Reservation>& getReservations();
    void addReservation(const Reservation& reservation);
};

#endif // HEADERS_MODEL_CLIENT_H_
