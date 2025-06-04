// Utils.cpp

#include "utils/Utils.h"
#include <iostream>
#include <limits>

int Utils::getInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

std::string Utils::getString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

Date Utils::getDate(const std::string& label) {
    std::cout << label << " date:\n";
    int day = getInt("  Day: ");
    int month = getInt("  Month: ");
    int year = getInt("  Year: ");
    return Date(day, month, year);
}

void Utils::pause(const std::string& message) {
    std::cout << message;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
