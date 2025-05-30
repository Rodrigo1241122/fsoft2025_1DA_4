// RoomNotAvailableException.h - tiago

#ifndef HEADERS_EXCEPTIONS_ROOMNOTAVAILABLEEXCEPTION_H_
#define HEADERS_EXCEPTIONS_ROOMNOTAVAILABLEEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class RoomNotAvailableException : public exception {
private:
    string data;

public:
    explicit RoomNotAvailableException(const string& data);
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_ROOMNOTAVAILABLEEXCEPTION_H_ */
