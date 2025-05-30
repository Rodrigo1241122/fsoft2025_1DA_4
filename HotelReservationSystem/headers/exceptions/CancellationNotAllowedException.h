// CancellationNotAllowedException.h - tiago

#ifndef HEADERS_EXCEPTIONS_CANCELLATIONNOTALOWEDEXCEPTION_H_
#define HEADERS_EXCEPTIONS_CANCELLATIONNOTALOWEDEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class CancellationNotAllowedException : public exception {
private:
    string data;

public:
    explicit CancellationNotAllowedException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_CANCELLATIONNOTALOWEDEXCEPTION_H_ */
