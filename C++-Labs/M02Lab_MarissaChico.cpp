#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int choice;
    double time, speed, distance;

    // Display menu
    cout << "Select a gas:\n";
    cout << "1. Carbon dioxide\n";
    cout << "2. Air\n";
    cout << "3. Helium\n";
    cout << "4. Hydrogen\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // Validate menu choice
    while (choice < 1 || choice > 4) {
        cout << "Invalid choice. Please enter a number between 1 and 4: ";
        cin >> choice;
    }

    // Ask for time
    cout << "Enter the time in seconds (0 - 30): ";
    cin >> time;

    // Validate time
    while (time < 0 || time > 30) {
        cout << "Invalid time. Enter a value between 0 and 30 seconds: ";
        cin >> time;
    }

    // Determine speed based on user's choice
    switch (choice) {
        case 1: speed = 258.0; break;   // Carbon dioxide
        case 2: speed = 331.5; break;   // Air
        case 3: speed = 972.0; break;   // Helium
        case 4: speed = 1270.0; break;  // Hydrogen
    }

    // Calculate distance
    distance = speed * time;

    // Display result
    cout << fixed << setprecision(2);
    cout << "The sound traveled " << distance << " meters." << endl;

    return 0;
}
