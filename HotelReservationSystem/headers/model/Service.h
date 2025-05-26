// Service.h - tiago

#ifndef HEADERS_MODEL_SERVICE_H_
#define HEADERS_MODEL_SERVICE_H_

#include <string>
#include "Date.h"

using namespace std;

class Service {
private:
    static int CODE;
    int serviceCode;
    string name;
    string description;
    float price;
    Date availableDate;

public:
    Service(const string& name, const string& description, float price, const Date& availableDate);
    Service(const Service& obj);
    ~Service();

    const string& getName() const;
    void setName(const string& name);

    const string& getDescription() const;
    void setDescription(const string& description);

    float getPrice() const;
    void setPrice(float price);

    const Date& getAvailableDate() const;
    void setAvailableDate(const Date& date);

    int getServiceCode() const;
    void setServiceCode(int code);

    bool operator == (const Service& obj) const;
    bool operator == (int code) const;
};

#endif /* HEADERS_MODEL_SERVICE_H_ */
