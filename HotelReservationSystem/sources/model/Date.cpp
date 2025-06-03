// Date.cpp - tiago

#include "model/Date.h"

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
