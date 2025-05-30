// AccountAlreadyExistsException.h - tiago

#ifndef HEADERS_EXCEPTIONS_ACCOUNTALREADYEXISTSEXCEPTION_H_
#define HEADERS_EXCEPTIONS_ACCOUNTALREADYEXISTSEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class AccountAlreadyExistsException : public exception {
private:
    string data;

public:
    explicit AccountAlreadyExistsException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_ACCOUNTALREADYEXISTSEXCEPTION_H_ */
