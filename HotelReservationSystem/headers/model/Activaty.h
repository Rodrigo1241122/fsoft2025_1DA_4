// Activity.h - tiago

#ifndef HEADERS_MODEL_ACTIVITY_H_
#define HEADERS_MODEL_ACTIVITY_H_

#include <string>
#include "Date.h"

using namespace std;

class Activity {
private:
    static int CODE;
    int activityCode;
    string title;
    string description;
    Date scheduledDate;
    int maxParticipants;

public:
    Activity(const string& title, const string& description, const Date& scheduledDate, int maxParticipants);
    Activity(const Activity& obj);
    ~Activity();

    const string& getTitle() const;
    void setTitle(const string& title);

    const string& getDescription() const;
    void setDescription(const string& description);

    const Date& getScheduledDate() const;
    void setScheduledDate(const Date& date);

    int getMaxParticipants() const;
    void setMaxParticipants(int max);

    int getActivityCode() const;
    void setActivityCode(int code);

    bool operator == (const Activity& obj) const;
    bool operator == (int code) const;
};

#endif /* HEADERS_MODEL_ACTIVITY_H_ */
