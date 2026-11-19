#include "models/Train.h"
#include <iostream>
#include <iomanip>

Train::Train(int num, const std::string& name, const std::string& src,
             const std::string& dest, int seats, double fare)
    : trainNumber(num), trainName(name), source(src), destination(dest),
      totalSeats(seats), availableSeats(seats), baseFare(fare) {}

void Train::displayTrainDetails() const {
    std::cout << std::left << std::setw(10) << trainNumber
              << std::setw(22) << trainName
              << std::setw(14) << getTrainType()
              << std::setw(15) << source
              << std::setw(15) << destination
              << std::setw(10) << availableSeats
              << "$" << std::fixed << std::setprecision(2) << calculateFare() << std::endl;
}

bool Train::bookSeat() {
    if (availableSeats > 0) {
        availableSeats--;
        return true;
    }
    return false;
}

void Train::cancelSeat() {
    if (availableSeats < totalSeats) {
        availableSeats++;
    }
}

int Train::getTrainNumber() const { return trainNumber; }
std::string Train::getTrainName() const { return trainName; }
std::string Train::getSource() const { return source; }
std::string Train::getDestination() const { return destination; }
int Train::getAvailableSeats() const { return availableSeats; }
void Train::setAvailableSeats(int seats) { availableSeats = seats; }
