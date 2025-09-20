#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int MAX_FLOORS = 16;
    const int MAX_PER_FLOOR = 6;

    int occupiedTotal = 0;

    for (int floor = 1; floor <= MAX_FLOORS; ++floor) {
        if (floor == 13) {                 // Skip the 13th floor
            continue;
        }

        int occupied = -1;
        // Input validation: 0..6 only
        while (occupied < 0 || occupied > MAX_PER_FLOOR) {
            cout << "Floor " << floor << " - apartments occupied (0-" << MAX_PER_FLOOR << "): ";
            if (!(cin >> occupied)) {      // Handle non-integer input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                occupied = -1;
            }
        }
        occupiedTotal += occupied;
    }

    const int totalFloorsCounted = MAX_FLOORS - 1; // no 13th floor
    const int totalApts = totalFloorsCounted * MAX_PER_FLOOR;
    const int unoccupied = totalApts - occupiedTotal;
    const double pct = totalApts == 0 ? 0.0 : (100.0 * occupiedTotal / totalApts);

    cout << "\n=== Building Occupancy Summary ===\n";
    cout << "Total apartments:      " << totalApts << '\n';
    cout << "Occupied apartments:   " << occupiedTotal << '\n';
    cout << "Unoccupied apartments: " << unoccupied << '\n';
    cout << fixed << setprecision(2)
         << "Percent occupied:      " << pct << "%\n";

    return 0;
}
