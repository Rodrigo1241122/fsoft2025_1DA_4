// Service.h - Tiago

#ifndef HEADERS_MODEL_SERVICE_H_
#define HEADERS_MODEL_SERVICE_H_

#include <string>
#include "Date.h"

class Service {
private:
    static int CODE;
    int serviceCode;
    std::string name;
    std::string description;
    float price;
    Date availableDate;

public:
    Service(const std::string& name, const std::string& description, float price, const Date& availableDate);
    Service(const Service& obj);
    ~Service();

    const std::string& getName() const;
    void setName(const std::string& name);

    const std::string& getDescription() const;
    void setDescription(const std::string& description);

    float getPrice() const;
    void setPrice(float price);

    const Date& getAvailableDate() const;
    void setAvailableDate(const Date& date);

    int getServiceCode() const;
    void setServiceCode(int code);

    int getId() const; // novo alias para getServiceCode()

    bool operator==(const Service& obj) const;
    bool operator==(int code) const;
};

#endif /* HEADERS_MODEL_SERVICE_H_ */
