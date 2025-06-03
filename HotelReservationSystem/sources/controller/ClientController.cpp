// ClientController.cpp - Rodrigo

#include "headers/controllers/ClientController.h"
#include "headers/utils/Validation.h"
#include "headers/utils/Logger.h"

void ClientController::createClient(const std::string& name, const std::string& email, const std::string& phone, const Date& birthDate) {
    if (!Validation::isValidEmail(email)) {
        Logger::error("Invalid email format");
        return;
    }
    if (!Validation::isValidPhoneNumber(phone)) {
        Logger::error("Invalid phone number");
        return;
    }

    Client* newClient = new Client(name, email, phone, birthDate);
    clients.push_back(newClient);
    Logger::info("Client created successfully");
}

Client* ClientController::findClientByID(int id) {
    for (Client* c : clients) {
        if (*c == id)
            return c;
    }
    return nullptr;
}

void ClientController::updateClientEmail(int id, const std::string& newEmail) {
    Client* client = findClientByID(id);
    if (client && Validation::isValidEmail(newEmail)) {
        client->setEmail(newEmail);
        Logger::info("Email updated.");
    } else {
        Logger::error("Invalid client or email.");
    }
}

void ClientController::removeClient(int id) {
    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if ((**it) == id) {
            delete *it;
            clients.erase(it);
            Logger::info("Client removed.");
            return;
        }
    }
    Logger::error("Client not found.");
}

std::vector<Client*> ClientController::listAllClients() const {
    return clients;
}
