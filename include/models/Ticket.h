#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "models/Passenger.h"

class Ticket {
private:
    int pnr;
    int trainNumber;
    std::string trainName;
    Passenger passenger;
    double farePaid;
    std::string status;

public:
    Ticket(int pnrNum, int tNum, const std::string& tName,
           const Passenger& p, double fare, const std::string& stat = "CONFIRMED");

    int getPNR() const;
    int getTrainNumber() const;
    std::string getTrainName() const;
    Passenger getPassenger() const;
    double getFarePaid() const;
    std::string getStatus() const;

    void cancelTicket();
    void displayTicket() const;
};

#endif // TICKET_H
