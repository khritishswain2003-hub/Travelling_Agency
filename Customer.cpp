#include "Customer.h"
#include <iostream>
#include <limits>

Customer::Customer()
    : clientNo(0),
      distance(0),
      days(0),
      seats(0),
      perKm(0.0),
      temporaryPermit(0.0),
      totalCost(0.0)
{
}

int Customer::getClientNo() const {
    return clientNo;
}

void Customer::input() {
    std::cout << "\n--- Customer Registration ---\n";

    std::cout << "Client Number: ";
    std::cin >> clientNo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Address: ";
    std::getline(std::cin, address);

    std::cout << "Phone: ";
    std::getline(std::cin, phone);

    std::cout << "Registration Date (DD-MM-YYYY): ";
    std::getline(std::cin, registrationDate);

    std::cout << "Route / Place: ";
    std::getline(std::cin, route);

    std::cout << "Total Distance (km): ";
    std::cin >> distance;

    std::cout << "Number of Days: ";
    std::cin >> days;

    std::cout << "Number of Seats (6, 10, or 16): ";
    std::cin >> seats;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Vehicle (TRAVELS/SUMO/INDICA): ";
    std::getline(std::cin, vehicle);

    std::cout << "Board (YELLOW/WHITE): ";
    std::getline(std::cin, board);

    std::cout << "Cost per km: ";
    std::cin >> perKm;

    std::cout << "Temporary Permit (TP): ";
    std::cin >> temporaryPermit;

    if (board == "YELLOW" || board == "yellow") {
        totalCost = (perKm + temporaryPermit) * distance;
    } else {
        totalCost = perKm * distance;
    }
}

void Customer::display() const {
    std::cout << "\n--- Customer Details ---\n";
    std::cout << "Client Number: " << clientNo << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Address: " << address << '\n';
    std::cout << "Phone: " << phone << '\n';
    std::cout << "Registration Date: " << registrationDate << '\n';
    std::cout << "Route: " << route << '\n';
    std::cout << "Distance: " << distance << " km\n";
    std::cout << "Days: " << days << '\n';
    std::cout << "Seats: " << seats << '\n';
    std::cout << "Vehicle: " << vehicle << '\n';
    std::cout << "Board: " << board << '\n';
    std::cout << "Total Cost: " << totalCost << '\n';
}

void Customer::saveToFile(std::ofstream& file) const {
    file << clientNo << '\n';
    file << name << '\n';
    file << address << '\n';
    file << phone << '\n';
    file << registrationDate << '\n';
    file << route << '\n';
    file << distance << '\n';
    file << days << '\n';
    file << seats << '\n';
    file << vehicle << '\n';
    file << board << '\n';
    file << perKm << '\n';
    file << temporaryPermit << '\n';
    file << totalCost << '\n';
}

bool Customer::loadFromFile(std::ifstream& file) {
    if (!(file >> clientNo)) {
        return false;
    }

    file.ignore();

    std::getline(file, name);
    std::getline(file, address);
    std::getline(file, phone);
    std::getline(file, registrationDate);
    std::getline(file, route);

    file >> distance;
    file >> days;
    file >> seats;

    file.ignore();

    std::getline(file, vehicle);
    std::getline(file, board);

    file >> perKm;
    file >> temporaryPermit;
    file >> totalCost;

    file.ignore();

    return true;
}
