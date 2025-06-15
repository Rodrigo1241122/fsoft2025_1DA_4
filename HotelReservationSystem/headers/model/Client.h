#ifndef HEADERS_MODEL_CLIENT_H_
#define HEADERS_MODEL_CLIENT_H_

#include <string>
#include <vector>
#include <ctime>
#include "model/Reservation.h"

// =============================
//         Classe Client
// =============================
class Client {
private:
    static int ID;             // Gerador de IDs automáticos (se usado)
    int clientID;
    std::string name;
    std::string email;
    std::string password;
    double balance = 0.0;
    time_t lastPaymentDate = 0;      // Data do último pagamento (epoch time)
    double lastPaymentAmount = 0.0;  // Valor do último pagamento

    std::vector<Reservation> reservations;

public:
    // ==== Construtores e destrutor ====
    Client(const std::string& name, const std::string& email, const std::string& password, double balance = 0.0);
    Client(const Client& obj);
    ~Client();

    // ==== Getters e setters principais ====
    const std::string& getName() const;
    void setName(const std::string& name);

    const std::string& getEmail() const;
    void setEmail(const std::string& email);

    const std::string& getPassword() const;
    void setPassword(const std::string& password);

    int getClientID() const;
    void setClientID(int id);

    // ==== Operadores de comparação ====
    bool operator==(const Client& obj) const;
    bool operator==(int id) const;

    // ==== Gestão de saldo ====
    void setBalance(double value);
    double getBalance() const;
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
