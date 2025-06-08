#ifndef HEADERS_MODEL_CLIENT_H_
#define HEADERS_MODEL_CLIENT_H_

#include <string>
#include <ctime>
#include "model/Date.h"

using namespace std;

class Client {
private:
    static int ID;
    int clientID;
    string name;
    string email;
    float balance;
    time_t lastPaymentDate;
    double lastPaymentAmount;

public:
    Client(const std::string& name, const std::string& email);
    Client(const Client& obj);
    ~Client();

    const string& getName() const;
    void setName(const string& name);

    const string& getEmail() const;
    void setEmail(const string& email);

    int getClientID() const;
    void setClientID(int id);

    bool operator == (const Client& obj) const;
    bool operator == (int id) const;

    void setBalance(float value);
    float getBalance() const;
    void addBalance(double amount);  // Novo método para adicionar saldo

    void setLastPaymentDate(time_t date);  // Novo método para definir a data do último pagamento
    time_t getLastPaymentDate() const;

    void setLastPaymentAmount(double amount);  // Novo método para definir o valor do último pagamento
    double getLastPaymentAmount() const;
};

#endif /* HEADERS_MODEL_CLIENT_H_ */
