// Coupon.h - tiago

#ifndef HEADERS_MODEL_COUPON_H_
#define HEADERS_MODEL_COUPON_H_

#include <string>
#include "Date.h"

using namespace std;

class Coupon {
private:
    static int CODE;
    int couponCode;
    string description;
    float discountPercentage; // entre 0 e 100
    Date validUntil;

public:
    Coupon(const string& description, float discountPercentage, const Date& validUntil);
    Coupon(const Coupon& obj);
    ~Coupon();

    const string& getDescription() const;
    void setDescription(const string& description);

    float getDiscountPercentage() const;
    void setDiscountPercentage(float discount);

    const Date& getValidUntil() const;
    void setValidUntil(const Date& date);

    int getCouponCode() const;
    void setCouponCode(int code);

    bool operator == (const Coupon& obj) const;
    bool operator == (int code) const;
};

#endif /* HEADERS_MODEL_COUPON_H_ */
