// PaymentFailedException.h - tiago

#ifndef HEADERS_EXCEPTIONS_PAYMENTFAILEDEXCEPTION_H_
#define HEADERS_EXCEPTIONS_PAYMENTFAILEDEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class PaymentFailedException : public exception {
private:
    string data;

public:
    explicit PaymentFailedException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_PAYMENTFAILEDEXCEPTION_H_ */
