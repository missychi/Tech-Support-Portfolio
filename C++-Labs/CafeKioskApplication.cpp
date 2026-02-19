// Cafe Kiosk Console Application
// Team: Marissa & Katherine
// Date: 05/05/2025
// Purpose: Simulate Cafe Kiosk with Manager and Customer mode

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes
void displayHomeMenu();
void managerMode();
bool authenticateManager();
void displayMenu();
void addMenuItem();
void toggleMaintenanceMode();
bool isInMaintenanceMode();
void customerMode();
void placeOrder();
void showFinalBill(double total);

const string MENU_FILE = "menu.txt";
const string CRED_FILE = "credentials.txt";
const string MAINTENANCE_FILE = "maintenance.txt";

int main() {
    int choice;
    do {
        displayHomeMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                managerMode();
                break;
            case 2:
                customerMode();
                break;
            case 3:
                cout << "Thank you for using the kiosk. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select again.\n";
        }
    } while (choice != 3);

    return 0;
}

void displayHomeMenu() {
    cout << "\n=== Welcome to the Café Kiosk ===" << endl;
    cout << "1. Manager" << endl;
    cout << "2. Customer" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

// Stub functions below (to be implemented)
void managerMode() {
    if (!authenticateManager()) {
        cout << "Authentication failed. Returning to Home Menu.\n";
        return;
    }

    int choice;
    do {
        cout << "\n=== Manager Menu ===" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Toggle Maintenance Mode" << endl;
        cout << "3. Add Menu Item" << endl;
        cout << "4. Back to Home Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                toggleMaintenanceMode();
                break;
            case 3:
                addMenuItem();
                break;
            case 4:
                cout << "Returning to Home Menu.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);
}

bool authenticateManager() {
    string username, password, fileUser, filePass;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    ifstream credFile(CRED_FILE);
    if (!credFile) {
        cout << "Could not open credentials file.\n";
        return false;
    }

    while (getline(credFile, fileUser, ';') && getline(credFile, filePass)) {
        if (fileUser == username && filePass == password)
            return true;
    }
    return false;
}

void displayMenu() {
    ifstream menuFile(MENU_FILE);
    if (!menuFile) {
        cout << "Error opening menu file.\n";
        return;
    }

    string item;
    double price;
    cout << fixed << setprecision(2);
    cout << "\n=== Café Menu ===" << endl;
    while (getline(menuFile, item, ';') && menuFile >> price) {
        menuFile.ignore(); // skip newline
        cout << item << " - $" << price << endl;
    }
}

void toggleMaintenanceMode() {
    bool currentMode = isInMaintenanceMode();
    ofstream outFile(MAINTENANCE_FILE);
    outFile << (currentMode ? 0 : 1);
    cout << "Maintenance Mode is now " << (currentMode ? "OFF" : "ON") << ".\n";
}

bool isInMaintenanceMode() {
    ifstream inFile(MAINTENANCE_FILE);
    int mode = 0;
    if (inFile >> mode)
        return mode == 1;
    return false;
}

void addMenuItem() {
    string name;
    double price;
    cout << "Enter item name: ";
    getline(cin, name);
    cout << "Enter item price: ";
    cin >> price;
    cin.ignore();

    ofstream menuFile(MENU_FILE, ios::app);
    menuFile << name << ";" << price << endl;
    cout << "Item added successfully.\n";
}

void customerMode() {
    if (isInMaintenanceMode()) {
        cout << "\nThe kiosk is currently undergoing repairs.\nWe are unable to take any orders at this time.\nWe apologize for the inconvenience.\n";
        return;
    }

    int choice;
    double total = 0.0;
    do {
        cout << "\n=== Customer Menu ===" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Place Order" << endl;
        cout << "3. Cancel Order" << endl;
        cout << "4. Done" << endl;
        cout << "5. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                placeOrder(); // To be fully implemented
                break;
            case 3:
                total = 0.0;
                cout << "Order cancelled.\n";
                break;
            case 4:
                showFinalBill(total);
                return;
            case 5:
                cout << "Returning to Home Menu.\n";
                return;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);
}

void placeOrder() {
    // TODO: Implement order cart system
    cout << "Ordering not yet implemented.\n";
}

void showFinalBill(double total) {
    const double TAX_RATE = 0.07;
    double tax = total * TAX_RATE;
    double finalTotal = total + tax;
    cout << fixed << setprecision(2);
    cout << "\nYour order has been taken. Please proceed to the register to pay $"
         << finalTotal << " and collect your food. Thank you, and please visit again.\n";
}
