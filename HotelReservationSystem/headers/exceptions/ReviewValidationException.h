// ReviewValidationException.h - tiago

#ifndef HEADERS_EXCEPTIONS_REVIEWVALIDATIONEXCEPTION_H_
#define HEADERS_EXCEPTIONS_REVIEWVALIDATIONEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class ReviewValidationException : public exception {
private:
    string data;

public:
    explicit ReviewValidationException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_REVIEWVALIDATIONEXCEPTION_H_ */
