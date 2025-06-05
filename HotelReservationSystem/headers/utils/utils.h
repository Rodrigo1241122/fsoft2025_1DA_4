#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "model/Date.h"

class Utils {
public:
    static int getInt(const std::string& prompt);

    static std::string getString(const std::string& prompt);

    static Date getDate(const std::string& label);

    static void pause(const std::string& message = "Press ENTER to continue...");
};

#endif // UTILS_H
