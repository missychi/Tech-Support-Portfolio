#include <iostream>
#include <string>
using namespace std;

// Structure to hold bin information
struct Bin
{
    string description;
    int parts;
};

// Function prototypes
void displayBins(const Bin bins[], int size);
void addParts(Bin &bin, int amount);
void removeParts(Bin &bin, int amount);

int main()
{
    const int SIZE = 10;

    // Initialize the bins with the given data
    Bin bins[SIZE] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    int choice, binChoice, amount;

    do
    {
        cout << "\n===== INVENTORY BIN LIST =====\n";
        displayBins(bins, SIZE);

        cout << "\nSelect a bin by number (1-10) or 0 to quit: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice < 1 || choice > SIZE)
        {
            cout << "Invalid bin selection.\n";
            continue;
        }

        binChoice = choice - 1;  // convert to array index

        cout << "You selected: " << bins[binChoice].description << endl;
        cout << "1. Add parts\n2. Remove parts\nChoose an option: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "How many parts to add? ";
            cin >> amount;
            addParts(bins[binChoice], amount);
        }
        else if (choice == 2)
        {
            cout << "How many parts to remove? ";
            cin >> amount;
            removeParts(bins[binChoice], amount);
        }
        else
        {
            cout << "Invalid option.\n";
        }

    } while (true);

    cout << "\nProgram ended.\n";
    return 0;
}

// Displays all bins with their part counts
void displayBins(const Bin bins[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << bins[i].description
             << " — Parts: " << bins[i].parts << endl;
    }
}

// Adds parts to a bin
void addParts(Bin &bin, int amount)
{
    if (amount < 0)
    {
        cout << "Cannot add a negative amount.\n";
        return;
    }
    bin.parts += amount;
}

// Removes parts from a bin
void removeParts(Bin &bin, int amount)
{
    if (amount < 0)
    {
        cout << "Cannot remove a negative amount.\n";
        return;
    }
    if (amount > bin.parts)
    {
        cout << "Not enough parts in the bin.\n";
        return;
    }
    bin.parts -= amount;
}








