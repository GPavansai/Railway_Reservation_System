#include "services/ReservationSystem.h"
#include "models/ExpressTrain.h"
#include "models/SuperfastTrain.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cctype>

ReservationSystem::ReservationSystem() : nextPNR(1001) {
    trains.push_back(std::make_unique<ExpressTrain>(101, "Coastal Express", "Chennai", "Vizag", 50, 45.00));
    trains.push_back(std::make_unique<SuperfastTrain>(202, "Deccan Queen SF", "Hyderabad", "Pune", 40, 60.00, 20.00));
    trains.push_back(std::make_unique<ExpressTrain>(303, "Krishna Express", "Vijayawada", "Tirupati", 60, 35.00));
    trains.push_back(std::make_unique<SuperfastTrain>(404, "Vande Bharat SF", "Secunderabad", "Bengaluru", 30, 85.00, 25.00));

    loadTicketsFromFile();
}

ReservationSystem::~ReservationSystem() {
    saveTicketsToFile();
}

Train* ReservationSystem::findTrain(int trainNum) const {
    for (const auto& t : trains) {
        if (t->getTrainNumber() == trainNum) {
            return t.get();
        }
    }
    return nullptr;
}

void ReservationSystem::saveTicketsToFile() const {
    std::ofstream outFile(dataFile);
    if (!outFile) return;

    outFile << nextPNR << "\n";
    for (const auto& t : tickets) {
        outFile << t.getPNR() << "|"
                << t.getTrainNumber() << "|"
                << t.getTrainName() << "|"
                << t.getPassenger().getName() << "|"
                << t.getPassenger().getAge() << "|"
                << t.getPassenger().getGender() << "|"
                << t.getFarePaid() << "|"
                << t.getStatus() << "\n";
    }
    outFile.close();
}

void ReservationSystem::loadTicketsFromFile() {
    std::ifstream inFile(dataFile);
    if (!inFile) return;

    inFile >> nextPNR;
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        std::vector<std::string> tokens;
        size_t start = 0, end = 0;
        while ((end = line.find('|', start)) != std::string::npos) {
            tokens.push_back(line.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(line.substr(start));

        if (tokens.size() == 8) {
            int pnr = std::stoi(tokens[0]);
            int tNum = std::stoi(tokens[1]);
            std::string tName = tokens[2];
            Passenger p(tokens[3], std::stoi(tokens[4]), tokens[5][0]);
            double fare = std::stod(tokens[6]);
            std::string status = tokens[7];

            tickets.emplace_back(pnr, tNum, tName, p, fare, status);

            if (status == "CONFIRMED") {
                Train* tr = findTrain(tNum);
                if (tr) tr->bookSeat();
            }
        }
    }
    inFile.close();
}

void ReservationSystem::viewAllTrains() const {
    std::cout << "\n=========================================================================================\n";
    std::cout << std::left << std::setw(10) << "Train No"
              << std::setw(22) << "Train Name"
              << std::setw(14) << "Type"
              << std::setw(15) << "Source"
              << std::setw(15) << "Destination"
              << std::setw(10) << "Seats"
              << "Fare" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------\n";
    for (const auto& t : trains) {
        t->displayTrainDetails();
    }
    std::cout << "=========================================================================================\n";
}

void ReservationSystem::bookTicket() {
    viewAllTrains();
    int tNum;
    std::cout << "\nEnter Train Number to book: ";
    std::cin >> tNum;

    Train* selectedTrain = findTrain(tNum);
    if (!selectedTrain) {
        std::cout << "[Error] Invalid Train Number.\n";
        return;
    }

    if (selectedTrain->getAvailableSeats() <= 0) {
        std::cout << "[Error] Sorry, no seats available on " << selectedTrain->getTrainName() << ".\n";
        return;
    }

    std::string name;
    int age;
    char gender;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter Passenger Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Passenger Age: ";
    std::cin >> age;

    std::cout << "Enter Gender (M/F/O): ";
    std::cin >> gender;
    gender = static_cast<char>(std::toupper(static_cast<unsigned char>(gender)));

    if (selectedTrain->bookSeat()) {
        Passenger p(name, age, gender);
        double finalFare = selectedTrain->calculateFare();
        Ticket newTicket(nextPNR, tNum, selectedTrain->getTrainName(), p, finalFare);
        tickets.push_back(newTicket);

        std::cout << "\n[Success] Ticket Booked! Your PNR is: " << nextPNR
                  << " | Total Fare: $" << std::fixed << std::setprecision(2) << finalFare << "\n";
        nextPNR++;
        saveTicketsToFile();
    }
}

void ReservationSystem::cancelTicket() {
    int pnr;
    std::cout << "\nEnter PNR Number to cancel: ";
    std::cin >> pnr;

    for (auto& t : tickets) {
        if (t.getPNR() == pnr) {
            if (t.getStatus() == "CANCELLED") {
                std::cout << "[Info] Ticket with PNR " << pnr << " is already cancelled.\n";
                return;
            }

            t.cancelTicket();
            Train* tr = findTrain(t.getTrainNumber());
            if (tr) {
                tr->cancelSeat();
            }

            std::cout << "[Success] Ticket PNR " << pnr << " cancelled. Seat restored to inventory.\n";
            saveTicketsToFile();
            return;
        }
    }
    std::cout << "[Error] PNR " << pnr << " not found.\n";
}

void ReservationSystem::viewAllBookings() const {
    if (tickets.empty()) {
        std::cout << "\n[Info] No bookings found.\n";
        return;
    }

    std::cout << "\n========================================================================================================\n";
    std::cout << std::left << std::setw(10) << "PNR"
              << std::setw(10) << "Train No"
              << std::setw(20) << "Train Name"
              << std::setw(20) << "Passenger"
              << std::setw(6) << "Age"
              << std::setw(8) << "Gender"
              << std::setw(10) << "Fare"
              << "Status" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------\n";
    for (const auto& t : tickets) {
        t.displayTicket();
    }
    std::cout << "========================================================================================================\n";
}

void ReservationSystem::searchByPNR() const {
    int pnr;
    std::cout << "\nEnter PNR Number: ";
    std::cin >> pnr;

    for (const auto& t : tickets) {
        if (t.getPNR() == pnr) {
            std::cout << "\n--- Ticket Details ---\n";
            t.displayTicket();
            return;
        }
    }
    std::cout << "[Error] No ticket found with PNR " << pnr << ".\n";
}
