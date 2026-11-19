#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include <vector>
#include <string>
#include <memory>
#include "models/Train.h"
#include "models/Ticket.h"

class ReservationSystem {
private:
    std::vector<std::unique_ptr<Train>> trains;
    std::vector<Ticket> tickets;
    int nextPNR;
    const std::string dataFile = "data/bookings.txt";

    Train* findTrain(int trainNum) const;
    void saveTicketsToFile() const;
    void loadTicketsFromFile();

public:
    ReservationSystem();
    ~ReservationSystem();

    void viewAllTrains() const;
    void bookTicket();
    void cancelTicket();
    void viewAllBookings() const;
    void searchByPNR() const;
};

#endif // RESERVATIONSYSTEM_H
