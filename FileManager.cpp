#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveCustomers(const std::vector<Customer>& customers) {
    std::ofstream file("data/customers.txt");

    if (!file) {
        std::cout << "Error: Could not open customer file.\n";
        return;
    }

    for (const Customer& customer : customers) {
        customer.saveToFile(file);
    }

    file.close();
}

std::vector<Customer> FileManager::loadCustomers() {
    std::vector<Customer> customers;

    std::ifstream file("data/customers.txt");

    if (!file) {
        return customers;
    }

    Customer customer;

    while (customer.loadFromFile(file)) {
        customers.push_back(customer);
        customer = Customer();
    }

    file.close();

    return customers;
}