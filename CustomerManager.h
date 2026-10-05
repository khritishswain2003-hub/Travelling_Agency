#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include <vector>
#include "Customer.h"

class CustomerManager {
private:
    std::vector<Customer> customers;

public:
    CustomerManager();
    void registerCustomer();
    void displayAll() const;
    void searchCustomer() const;
    void modifyCustomer();
    void deleteCustomer();
};

#endif