# Railway Reservation System (C++ OOP)

A pure C++ modular console application demonstrating core Object-Oriented Programming principles: **Encapsulation**, **Abstraction**, **Inheritance**, **Polymorphism**, and **RAII**.

## Project Directory Structure

```text
RailwayReservationSystem/
├── include/
│   ├── models/
│   │   ├── ExpressTrain.h
│   │   ├── Passenger.h
│   │   ├── SuperfastTrain.h
│   │   ├── Ticket.h
│   │   └── Train.h
│   └── services/
│       └── ReservationSystem.h
├── src/
│   ├── models/
│   │   ├── ExpressTrain.cpp
│   │   ├── Passenger.cpp
│   │   ├── SuperfastTrain.cpp
│   │   ├── Ticket.cpp
│   │   └── Train.cpp
│   ├── services/
│   │   └── ReservationSystem.cpp
│   └── main.cpp
├── data/
│   └── .gitkeep
└── README.md
```

## Compile & Run (Pure g++ / C++)

Open a terminal inside the `RailwayReservationSystem` folder and run:

```bash
g++ -std=c++14 -Iinclude src/main.cpp src/models/*.cpp src/services/*.cpp -o railway_app
./railway_app
```

*(On Windows with MinGW: `g++ -std=c++14 -Iinclude src/main.cpp src/models/*.cpp src/services/*.cpp -o railway_app.exe` and run `railway_app.exe`)*
