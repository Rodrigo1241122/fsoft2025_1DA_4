// InvalidReservationDetailsException.h - tiago

#ifndef HEADERS_EXCEPTIONS_INVALIDRESERVATIONDETAILSEXCEPTION_H_
#define HEADERS_EXCEPTIONS_INVALIDRESERVATIONDETAILSEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class InvalidReservationDetailsException : public exception {
private:
    string data;

public:
    explicit InvalidReservationDetailsException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_INVALIDRESERVATIONDETAILSEXCEPTION_H_ */
