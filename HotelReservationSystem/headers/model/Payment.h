// Payment.h - tiago

#ifndef HEADERS_MODEL_PAYMENT_H_
#define HEADERS_MODEL_PAYMENT_H_

#include "Date.h"

class Payment {
private:
    static int CODE;
    int paymentCode;
    float amount;
    Date paymentDate;

public:
    Payment(float amount, const Date& paymentDate);
    Payment(const Payment& obj);
    ~Payment();

    float getAmount() const;
    void setAmount(float amount);

    const Date& getPaymentDate() const;
    void setPaymentDate(const Date& date);

    int getPaymentCode() const;
    void setPaymentCode(int code);

    bool operator == (const Payment& obj) const;
    bool operator == (int code) const;
};

#endif /* HEADERS_MODEL_PAYMENT_H_ */
