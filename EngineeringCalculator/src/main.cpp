#include <iostream>
#include <limits>

#include "../include/calculator.h"

using namespace std;

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Choose option: ";
        while(!(cin >> choice) || choice < 1 || choice > 12) {
            cout << "Please choose a number between 1 and 12";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: performAddition(); break;
            case 2: performSubtraction(); break;
            case 3: performMultiplication(); break;
            case 4: performDivision(); break;
            case 5: performSine(); break;
            case 6: performCosine(); break;
            case 7: performTangent(); break;
            case 8: performLogarithm(); break;
            case 9: performNaturalLogarithm(); break;
            case 10: performPower(); break;
            case 11: performSquareRoot(); break;
            case 12: cout << "Exiting the calculator.\n"; break;
            default: cout << "Invalid option. Please try again.\n";
        }
        cout << endl;
    } while(choice != 12);

    return 0;
}
