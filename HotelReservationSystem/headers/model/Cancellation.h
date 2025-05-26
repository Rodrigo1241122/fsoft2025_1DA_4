// Cancellation.h - tiago

#ifndef HEADERS_MODEL_CANCELLATION_H_
#define HEADERS_MODEL_CANCELLATION_H_

#include <string>
#include "Date.h"

using namespace std;

class Cancellation {
private:
    static int CODE;
    int cancellationCode;
    string reason;
    Date cancellationDate;

public:
    Cancellation(const string& reason, const Date& cancellationDate);
    Cancellation(const Cancellation& obj);
    ~Cancellation();

    const string& getReason() const;
    void setReason(const string& reason);

    const Date& getCancellationDate() const;
    void setCancellationDate(const Date& date);

    int getCancellationCode() const;
    void setCancellationCode(int code);

    bool operator == (const Cancellation& obj) const;
    bool operator == (int code) const;
};

#endif /* HEADERS_MODEL_CANCELLATION_H_ */
