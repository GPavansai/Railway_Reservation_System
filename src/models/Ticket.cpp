#include "models/Ticket.h"
#include <iostream>
#include <iomanip>

Ticket::Ticket(int pnrNum, int tNum, const std::string& tName,
               const Passenger& p, double fare, const std::string& stat)
    : pnr(pnrNum), trainNumber(tNum), trainName(tName),
      passenger(p), farePaid(fare), status(stat) {}

int Ticket::getPNR() const { return pnr; }
int Ticket::getTrainNumber() const { return trainNumber; }
std::string Ticket::getTrainName() const { return trainName; }
Passenger Ticket::getPassenger() const { return passenger; }
double Ticket::getFarePaid() const { return farePaid; }
std::string Ticket::getStatus() const { return status; }

void Ticket::cancelTicket() {
    status = "CANCELLED";
}

void Ticket::displayTicket() const {
    std::cout << std::left << std::setw(10) << pnr
              << std::setw(10) << trainNumber
              << std::setw(20) << trainName;
    passenger.display();
    std::cout << "$" << std::left << std::setw(9) << std::fixed << std::setprecision(2) << farePaid
              << status << std::endl;
}
