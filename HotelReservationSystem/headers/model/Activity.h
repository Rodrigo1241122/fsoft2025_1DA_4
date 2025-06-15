// Activity.h - Tiago

#ifndef HEADERS_MODEL_ACTIVITY_H_
#define HEADERS_MODEL_ACTIVITY_H_

#include <string>
#include "model/Date.h"

class Activity {
private:
    static int CODE;
    int activityCode;
    std::string title;
    std::string description;
    Date scheduledDate;
    int maxParticipants;
    int id;
    float price;

public:
    Activity(const std::string& title, const std::string& description, const Date& scheduledDate, int maxParticipants);
    Activity(const Activity& obj);
    Activity(int id, const std::string& title, const std::string& description, float price);
    ~Activity();

    const std::string& getTitle() const;
    void setTitle(const std::string& title);

    const std::string& getDescription() const;
    void setDescription(const std::string& description);

    const Date& getScheduledDate() const;
    void setScheduledDate(const Date& date);

    int getMaxParticipants() const;
    void setMaxParticipants(int max);

    int getActivityCode() const;
    void setActivityCode(int code);

    int getId() const;
    float getPrice() const;

    bool operator==(const Activity& obj) const;
    bool operator==(int code) const;
};

#endif /* HEADERS_MODEL_ACTIVITY_H_ */
