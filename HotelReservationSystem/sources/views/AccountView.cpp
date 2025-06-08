#include "AccountView.h"
#include "utils/utils.h"
#include <iostream>
#include <set>
#include <regex>
#include "model/Client.h"
#include "controller/Controller.h"

static std::set<std::string> existingEmails = {
    "teste@example.com",
    "user@site.pt"
};

static bool isValidEmailFormat(const std::string& email) {
    const std::regex pattern(R"(^[^@\s]+@[^@\s]+\.[^@\s]+$)");
    return std::regex_match(email, pattern);
}

static bool isEmailTaken(const std::string& email) {
    return existingEmails.count(email) > 0;
}

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

void AccountView::createAccount() const {
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

    existingEmails.insert(email);
    std::cout << "Account created successfully for " << name << " (" << email << ").\n";
}

void AccountView::login(Controller& controller) const {
    std::string email;

    while (true) {
        email = Utils::getString("Enter your email to login (or 0 to go back): ");
        if (email == "0") return;

        if (!isValidEmailFormat(email)) {
            std::cout << "Invalid email format. Try again.\n";
            continue;
        }

        if (!isEmailTaken(email)) {
            std::cout << "Email not found. Try again.\n";
            continue;
        }

        break;
    }

    std::string name = Utils::getString("Enter your name (or 0 to go back): ");
    if (name == "0") return;

    auto client = std::make_shared<Client>(name, email);
    client->setBalance(1000);
    controller.setCurrentClient(client);

    std::cout << "Login successful. Welcome back, " << name << "! Balance: " << client->getBalance() << "EUR\n";
    Utils::pause();
}


