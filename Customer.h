
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <fstream>
class Customer {
private:
    int clientNo;
    std::string name;
    std::string address;
    std::string phone;
    std::string registrationDate;

    std::string route;
    int distance;
    int days;
    int seats;

    std::string vehicle;
    std::string board;

    double perKm;
    double temporaryPermit;
    double totalCost;

public:
    Customer();

    void input();
    int getClientNo() const;
    void display( ) const;
    void saveToFile(std::ofstream& file) const;
    bool loadFromFile(std::ifstream& file);
};

#endif
