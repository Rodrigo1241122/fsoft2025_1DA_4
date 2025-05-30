// InvalidCredentialsException.h - tiago

#ifndef HEADERS_EXCEPTIONS_INVALIDCREDENTIALSEXCEPTION_H_
#define HEADERS_EXCEPTIONS_INVALIDCREDENTIALSEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class InvalidCredentialsException : public exception {
private:
    string data;

public:
    explicit InvalidCredentialsException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_INVALIDCREDENTIALSEXCEPTION_H_ */
