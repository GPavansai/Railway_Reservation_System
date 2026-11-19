#include "models/Passenger.h"
#include <iostream>
#include <iomanip>

Passenger::Passenger() : name(""), age(0), gender('M') {}

Passenger::Passenger(const std::string& name, int age, char gender)
    : name(name), age(age), gender(gender) {}

std::string Passenger::getName() const {
    return name;
}

int Passenger::getAge() const {
    return age;
}

char Passenger::getGender() const {
    return gender;
}

void Passenger::display() const {
    std::cout << std::left << std::setw(20) << name
              << std::setw(6) << age
              << std::setw(8) << gender;
}
