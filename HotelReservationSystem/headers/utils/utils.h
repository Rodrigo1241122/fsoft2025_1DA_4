#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "model/Date.h"

class Utils {
public:
    // Reads an integer with prompt and validation
    static int getInt(const std::string& prompt);

    // Reads a string from the user with a prompt
    static std::string getString(const std::string& prompt);

    // Prompts the user to input a date (day/month/year)
    static Date getDate(const std::string& label);

    // Pauses execution until user presses ENTER
    static void pause(const std::string& message = "Press ENTER to continue...");
};

#endif // UTILS_H
