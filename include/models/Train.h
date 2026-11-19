#ifndef TRAIN_H
#define TRAIN_H

#include <string>

// Abstract Base Class enforcing Abstraction & Polymorphism
class Train {
protected:
    int trainNumber;
    std::string trainName;
    std::string source;
    std::string destination;
    int totalSeats;
    int availableSeats;
    double baseFare;

public:
    Train(int num, const std::string& name, const std::string& src,
          const std::string& dest, int seats, double fare);

    virtual ~Train() = default;

    // Pure virtual methods
    virtual double calculateFare() const = 0;
    virtual std::string getTrainType() const = 0;

    // Polymorphic display
    virtual void displayTrainDetails() const;

    // Encapsulated seat management
    bool bookSeat();
    void cancelSeat();

    // Getters & Setters
    int getTrainNumber() const;
    std::string getTrainName() const;
    std::string getSource() const;
    std::string getDestination() const;
    int getAvailableSeats() const;
    void setAvailableSeats(int seats);
};

#endif // TRAIN_H
