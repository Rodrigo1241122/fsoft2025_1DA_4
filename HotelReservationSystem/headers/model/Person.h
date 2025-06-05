// Person.h - Martim
// Base class for Client - MODEL only

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
protected:
    string name;

public:
    Person();
    Person(const string& name);

    Person(const Person& other);

    virtual ~Person();

    const string& getName() const;

    void setName(const string& name);

    Person& operator=(const Person& other);

    bool operator==(const Person& other) const;
    bool operator!=(const Person& other) const;
};

#endif /* PERSON_H */