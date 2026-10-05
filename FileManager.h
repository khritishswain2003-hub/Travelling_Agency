#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <vector>
#include "Customer.h"

class FileManager {
public:
    static void saveCustomers(const std::vector<Customer>& customers);
    static std::vector<Customer> loadCustomers();
};

#endif