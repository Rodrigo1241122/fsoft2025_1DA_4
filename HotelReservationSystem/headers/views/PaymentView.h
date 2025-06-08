#ifndef HEADERS_VIEWS_PAYMENTVIEW_H_
#define HEADERS_VIEWS_PAYMENTVIEW_H_

#include <iostream>

class Controller; // Forward declaration

class PaymentView {
public:
    int menuPayment() const;
    void payReservation(Controller& controller);
    void printReceipt(const Controller& controller) const;
};

#endif /* HEADERS_VIEWS_PAYMENTVIEW_H_ */
