// ClientController.h - Rodrigo

#ifndef CONTROLLERS_CLIENTCONTROLLER_H_
#define CONTROLLERS_CLIENTCONTROLLER_H_

#include "model/Client.h"
#include <vector>
#include <string>

class ClientController {
public:
    void createClient(const std::string& name, const std::string& email, const std::string& phone, const Date& birthDate);
    Client* findClientByID(int id);
    void updateClientEmail(int id, const std::string& newEmail);
    void removeClient(int id);
    std::vector<Client*> listAllClients() const;

private:
    std::vector<Client*> clients;
};

#endif // CONTROLLERS_CLIENTCONTROLLER_H_
