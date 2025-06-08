#ifndef HEADERS_MODEL_DATE_H_
#define HEADERS_MODEL_DATE_H_

#include <ctime>  // Para time_t e tm

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

    int daysBetween(const Date& other) const;  // Adicionado para calcular a diferença em dias
    bool isBefore(const Date& obj) const;
    bool isAfter(const Date& obj) const;

    // Função para converter Date para time_t
    time_t toTimeT() const {
        tm t = {};
        t.tm_year = year - 1900;  // tm_year é o número de anos desde 1900
        t.tm_mon = month - 1;     // tm_mon vai de 0 a 11
        t.tm_mday = day;          // Dia do mês
        t.tm_hour = 0;            // Hora (opcional)
        t.tm_min = 0;             // Minuto (opcional)
        t.tm_sec = 0;             // Segundo (opcional)

        return mktime(&t);  // Converte tm para time_t
    }
};

// Função global para obter a data atual
Date getTodayDate();

#endif /* HEADERS_MODEL_DATE_H_ */
