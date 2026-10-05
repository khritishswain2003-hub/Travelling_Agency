
#include <iostream>
#include "CustomerManager.h"

using namespace std;

int main() {
    CustomerManager manager;
    int choice;

    do {
        cout << "\n";
        cout << "================================\n";
        cout << "    TRAVELING AGENCY SYSTEM\n";
        cout << "================================\n";
        cout << "1. Registration\n";
        cout << "2. Display All Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Modify (coming next)\n";
        cout << "5. Delete (coming next)\n";
        cout << "6. Exit\n";
        cout << "================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
                cout << "Invalid input! Enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

        switch (choice) {
            case 1:
                manager.registerCustomer();
                break;

            case 2:
                manager.displayAll();
                break;

            case 3:
                manager.searchCustomer();
                break;

            case 4:
                manager.modifyCustomer();
                break;
            case 5:
                cout << "Delete module coming next.\n";
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
