// Client.h - tiago

#ifndef HEADERS_MODEL_CLIENT_H_
#define HEADERS_MODEL_CLIENT_H_

#include <string>
#include "model/Date.h"

using namespace std;

class Client {
private:
    static int ID;
    int clientID;
    string name;
    string email;
    string phone;
    Date birthDate;

public:
    Client(const string& name, const string& email, const string& phone, const Date& birthDate);
    Client(const Client& obj);
    ~Client();

    const string& getName() const;
    void setName(const string& name);

    const string& getEmail() const;
    void setEmail(const string& email);

    const string& getPhone() const;
    void setPhone(const string& phone);

    const Date& getBirthDate() const;
    void setBirthDate(const Date& date);

    int getClientID() const;
    void setClientID(int id);

    bool operator == (const Client& obj) const;
    bool operator == (int id) const;
};

#endif /* HEADERS_MODEL_CLIENT_H_ */
