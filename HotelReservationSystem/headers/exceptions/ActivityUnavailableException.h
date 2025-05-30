// ActivityUnavailableException.h - tiago

#ifndef HEADERS_EXCEPTIONS_ACTIVITYUNAVAILABLEEXCEPTION_H_
#define HEADERS_EXCEPTIONS_ACTIVITYUNAVAILABLEEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class ActivityUnavailableException : public exception {
private:
    string data;

public:
    explicit ActivityUnavailableException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_ACTIVITYUNAVAILABLEEXCEPTION_H_ */
