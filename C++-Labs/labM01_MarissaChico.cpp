#include <iostream>
using namespace std;

int main() {
    // Variables
    double R, E, S, V;

    // Input
    cout << "Enter the length of the row (in feet): ";
    cin >> R;
    
    cout << "Enter the amount of space used by an end-post assembly (in feet): ";
    cin >> E;
    
    cout << "Enter the amount of space between vines (in feet): ";
    cin >> S;

    // Calculation using the formula V = (R - 2E) / S
    V = (R - 2 * E) / S;

    // Output
    cout << "The number of grapevines that will fit in the row is: " << V << endl;

    return 0;
}
