// CouponInvalidException.h - tiago

#ifndef HEADERS_EXCEPTIONS_COUPONINVALIDEEXCEPTION_H_
#define HEADERS_EXCEPTIONS_COUPONINVALIDEEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class CouponInvalidException : public exception {
private:
    string data;

public:
    explicit CouponInvalidException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_COUPONINVALIDEEXCEPTION_H_ */
