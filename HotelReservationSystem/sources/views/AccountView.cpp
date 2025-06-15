#include "AccountView.h"
#include "utils/utils.h"
#include <iostream>
#include <set>
#include <regex>
#include <memory>
#include "model/Client.h"
#include "controller/Controller.h"

// Conjunto de emails já registados para simulação rápida
static std::set<std::string> existingEmails = {
    "teste@example.com",
    "user@site.pt"
};

// Função auxiliar para validar formato de email com expressão regular
static bool isValidEmailFormat(const std::string& email) {
    const std::regex pattern(R"(^[^@\s]+@[^@\s]+\.[^@\s]+$)");
    return std::regex_match(email, pattern);
}

// Função auxiliar para verificar se um email já está em uso
static bool isEmailTaken(const std::string& email) {
    return existingEmails.count(email) > 0;
}

// =============================
//      Menu da conta
// =============================
int AccountView::menuAccount() const {
    int option;
    std::cout << "\n=== Account Menu ===\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Login\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}



void AccountView::createAccount(Controller& controller) const {
    std::string email;
    while (true) {
        email = Utils::getString("Enter your email (or 0 to go back): ");
        if (email == "0") return;

        if (!isValidEmailFormat(email)) {
            std::cout << "Invalid email format. Try again.\n";
            continue;
        }
        if (isEmailTaken(email)) {
            std::cout << "Email already in use. Try another.\n";
            continue;
        }
        break;
    }

    std::string name;
    while (true) {
        name = Utils::getString("Enter your name (or 0 to go back): ");
        if (name == "0") return;
        if (name.empty()) {
            std::cout << "Name cannot be empty. Try again.\n";
            continue;
        }
        break;
    }

    std::string password;
    while (true) {
        password = Utils::getString("Enter your password (or 0 to go back): ");
        if (password == "0") return;
        if (password.empty()) {
            std::cout << "Password cannot be empty. Try again.\n";
            continue;
        }
        break;
    }

    auto client = std::make_shared<Client>(name, email, password, 1000);
    controller.addClient(client);

    existingEmails.insert(email);

    std::cout << "Account created successfully for " << name << " (" << email << ").\n";
}
// =============================
//        Login
// =============================
void AccountView::login(Controller& controller) const {
    std::string email, password;
    bool loggedIn = false;

    while (!loggedIn) {
        // Pedir email
        email = Utils::getString("Enter your email to login (or 0 to go back): ");
        if (email == "0") return;

        if (!isValidEmailFormat(email)) {
            std::cout << "Invalid email format. Try again.\n";
            continue;
        }

        // Pedir password
        password = Utils::getString("Enter your password (or 0 to go back): ");
        if (password == "0") return;

        // Percorrer a lista de clientes para procurar email e password
        bool found = false;
        for (const auto& client : controller.getClients()) {
            if (client->getEmail() == email) {
                found = true;
                if (client->getPassword() == password) {
                    controller.setCurrentClient(client);
                    std::cout << "Login successful. Welcome back, " << client->getName()
                              << "! Balance: " << client->getBalance() << "EUR\n";
                    Utils::pause();
                    loggedIn = true;
                } else {
                    std::cout << "Incorrect password. Try again.\n";
                }
                break;
            }
        }
        if (!found) {
            std::cout << "Email not found. Try again.\n";
        }
    }
}

int AccountView::menu_logout() const {
    int option;
    std::cout << "\n=== Account Menu ===\n";
    std::cout << "1. Logout\n";
    std::cout << "0. Back\n";
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}

void AccountView::logout_confirmation() {
    std::cout << "You logged out successfully. \n\n\n";
}



