#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int secret = (rand() % 100) + 1;   // 1..100

    int guess;
    int guessCount = 0;

    cout << "I'm thinking of a number from 1 to 100.\n";

    do {
        cout << "Enter your guess: ";
        while (!(cin >> guess)) {            // Validate numeric input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter an integer from 1 to 100: ";
        }

        ++guessCount;

        if (guess > secret) {
            cout << "Too high, try again.\n";
        } else if (guess < secret) {
            cout << "Too low, try again.\n";
        }
    } while (guess != secret);

    cout << "Correct! You guessed it in " << guessCount << " attempt"
         << (guessCount == 1 ? "" : "s") << ".\n";

    return 0;
}
