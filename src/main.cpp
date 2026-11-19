#include "services/ReservationSystem.h"
#include <iostream>
#include <limits>

int main() {
    ReservationSystem system;
    int choice;

    while (true) {
        std::cout << "\n====== RAILWAY RESERVATION SYSTEM ======\n";
        std::cout << "1. View Available Trains\n";
        std::cout << "2. Book a Ticket\n";
        std::cout << "3. Cancel a Ticket\n";
        std::cout << "4. Search Ticket by PNR\n";
        std::cout << "5. View All Bookings\n";
        std::cout << "6. Exit\n";
        std::cout << "Select an option: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[Error] Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1: system.viewAllTrains(); break;
            case 2: system.bookTicket(); break;
            case 3: system.cancelTicket(); break;
            case 4: system.searchByPNR(); break;
            case 5: system.viewAllBookings(); break;
            case 6:
                std::cout << "Saving data and exiting...\n";
                return 0;
            default:
                std::cout << "[Error] Invalid choice. Try again.\n";
        }
    }
}
