#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    std::string name;
    int age;
    char gender;

public:
    Passenger();
    Passenger(const std::string& name, int age, char gender);

    std::string getName() const;
    int getAge() const;
    char getGender() const;

    void display() const;
};

#endif // PASSENGER_H
