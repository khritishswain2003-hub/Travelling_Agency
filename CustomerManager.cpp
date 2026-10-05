#include "CustomerManager.h"
#include "FileManager.h"
#include <iostream>

CustomerManager::CustomerManager() {
    customers = FileManager::loadCustomers();
}
void CustomerManager::registerCustomer() {
    Customer customer;
    customer.input();

    for (const Customer& existing : customers) {
        if (existing.getClientNo() == customer.getClientNo()) {
            std::cout << "Client number already exists!\n";
            return;
        }
    }

    customers.push_back(customer);

    FileManager::saveCustomers(customers);

    std::cout << "Customer registered successfully!\n";
}

void CustomerManager::displayAll() const {
    if (customers.empty()) {
        std::cout << "No customers registered yet.\n";
        return;
    }

    for (const Customer& customer : customers) {
        customer.display();
    }
}

void CustomerManager::searchCustomer() const {
    int number;
    std::cout << "Enter client number to search: ";
    std::cin >> number;

    for (const Customer& customer : customers) {
        if (customer.getClientNo() == number) {
            customer.display();
            return;
        }
    }

    std::cout << "Customer not found.\n";
}
void CustomerManager::modifyCustomer() {
    int number;

    std::cout << "Enter client number to modify: ";
    std::cin >> number;

    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].getClientNo() == number) {

            std::cout << "\nCustomer found.";
            std::cout << "\nEnter updated details:\n";

            Customer updated;
            updated.input();

            // Check whether the new number belongs
            // to another customer.
            for (size_t j = 0; j < customers.size(); j++) {
                if (i != j &&
                    customers[j].getClientNo() ==
                    updated.getClientNo()) {
                    std::cout << "Client number already exists!\n";
                    return;
                }
            }

            customers[i] = updated;
            FileManager::saveCustomers(customers);
            std::cout << "Customer updated successfully!\n";
            return;
        }
    }

    std::cout << "Customer not found.\n";
}
void CustomerManager::deleteCustomer() {
    int number;

    std::cout << "Enter client number to delete: ";
    std::cin >> number;

    for (size_t i = 0; i < customers.size(); i++) {

        if (customers[i].getClientNo() == number) {

            customers.erase(customers.begin() + i);


            // Save the updated customer list
            FileManager::saveCustomers(customers);

            std::cout << "Customer deleted successfully!\n";
            return;
        }
    }

    std::cout << "Customer not found.\n";
}
