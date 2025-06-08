#include "date.h"
#include <chrono>
#include <ctime>
#include <cstdlib>

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 2000;
}

Date::Date(int day, int month, int year) {
    setDate(day, month, year);
}

Date::Date(const Date& date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

bool Date::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool Date::isValid(int day, int month, int year) {
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;

    int maxDay;
    switch (month) {
        case 2:
            maxDay = isLeapYear(year) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;
        default:
            maxDay = 31;
    }

    return day >= 1 && day <= maxDay;
}

void Date::setDate(int day, int month, int year) {
    if (isValid(day, month, year)) {
        this->day = day;
        this->month = month;
        this->year = year;
    } else {
        this->day = 1;
        this->month = 1;
        this->year = 2000;
    }
}

void Date::getDate(int& day, int& month, int& year) const {
    day = this->day;
    month = this->month;
    year = this->year;
}

bool Date::operator==(const Date& obj) const {
    return this->day == obj.day && this->month == obj.month && this->year == obj.year;
}

bool Date::operator>(const Date& obj) const {
    if (this->year != obj.year) return this->year > obj.year;
    if (this->month != obj.month) return this->month > obj.month;
    return this->day > obj.day;
}

bool Date::operator<(const Date& obj) const {
    if (this->year != obj.year) return this->year < obj.year;
    if (this->month != obj.month) return this->month < obj.month;
    return this->day < obj.day;
}

Date getTodayDate() {
    using namespace std::chrono;
    system_clock::time_point today = system_clock::now();
    time_t today_time = system_clock::to_time_t(today);
    tm* today_tm = localtime(&today_time);

    return Date(today_tm->tm_mday, today_tm->tm_mon + 1, today_tm->tm_year + 1900);
}

int Date::daysBetween(const Date& other) const {
    int days1 = this->year * 365 + this->day;
    int days2 = other.year * 365 + other.day;

    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int m = 0; m < this->month - 1; m++) {
        days1 += daysInMonth[m];
    }
    for (int m = 0; m < other.month - 1; m++) {
        days2 += daysInMonth[m];
    }

    return std::abs(days1 - days2);
}

bool Date::isBefore(const Date& obj) const {
    if (this->year != obj.year) return this->year < obj.year;
    if (this->month != obj.month) return this->month < obj.month;
    return this->day < obj.day;
}

bool Date::isAfter(const Date& obj) const {
    if (this->year != obj.year) return this->year > obj.year;
    if (this->month != obj.month) return this->month > obj.month;
    return this->day > obj.day;
}
