// ServiceUnavailableException.h - tiago

#ifndef HEADERS_EXCEPTIONS_SERVICEUNAVAILABLEEXCEPTION_H_
#define HEADERS_EXCEPTIONS_SERVICEUNAVAILABLEEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class ServiceUnavailableException : public exception {
private:
    string data;

public:
    explicit ServiceUnavailableException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_SERVICEUNAVAILABLEEXCEPTION_H_ */
