// Service.h - Tiago

#ifndef HEADERS_MODEL_SERVICE_H_
#define HEADERS_MODEL_SERVICE_H_

#include <string>
#include "Date.h"

class Service {
private:
    int id; // Identificador único do serviço
    std::string name;
    std::string description;
    float price;
    Date availableDate;

public:
    // Construtor principal usado no seed e em todo o lado!
    Service(int id, const std::string& name, const std::string& description, float price);

    // Construtor de cópia
    Service(const Service& obj);

    // (Opcional) Construtor alternativo se usares datas:
    Service(const std::string& name, const std::string& description, float price, const Date& availableDate);

    ~Service();

    // Getters e Setters
    int getId() const; // Usado para mostrar o ID nos menus
    const std::string& getName() const;
    void setName(const std::string& name);
    const std::string& getDescription() const;
    void setDescription(const std::string& description);
    float getPrice() const;
    void setPrice(float price);
    const Date& getAvailableDate() const;
    void setAvailableDate(const Date& date);

    // Operadores de comparação
    bool operator==(const Service& obj) const;
    bool operator==(int code) const;
};

#endif /* HEADERS_MODEL_SERVICE_H_ */
