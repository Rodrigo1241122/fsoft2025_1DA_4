// Date.h - tiago

#ifndef HEADERS_MODEL_DATE_H_
#define HEADERS_MODEL_DATE_H_

class Date {
private:
    int day;
    int month; 
    int year;

    bool isLeapYear(int year);
    bool isValid(int day, int month, int year);

public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& date);

    void setDate(int day, int month, int year);
    void getDate(int& day, int& month, int& year) const;

    bool operator==(const Date& obj) const;
    bool operator>(const Date& obj) const;
    bool operator<(const Date& obj) const;
};

#endif /* HEADERS_MODEL_DATE_H_ */
