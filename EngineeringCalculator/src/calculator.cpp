#include <iostream>
#include <cmath>
#include <limits>
#include "../include/calculator.h"

using namespace std;

void displayMenu() {
    cout << "==== Engineering Calculator ====\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Sine\n";
    cout << "6. Cosine\n";
    cout << "7. Tangent\n";
    cout << "8. Logarithm (base 10)\n";
    cout << "9. Natural Logarithm (ln)\n";
    cout << "10. Power\n";
    cout << "11. Square Root\n";
    cout << "12. Exit\n";
}

double getNumber(const std::string &prompt) {
    double number;
    cout << prompt;
    while(!(cin >> number)) {
        cout << "Please enter a number";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}

void performAddition() {
    double a = getNumber("Enter first number : ");
    double b = getNumber("Enter second number : ");
    cout << "Result : " << a + b << endl;
}

void performSubtraction() {
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");
    cout << "Result: " << a - b << endl;
}

void performMultiplication() {
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");
    cout << "Result: " << a * b << endl;
}

void performDivision() {
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");
    if (b == 0) {
        cout << "Error: Division by zero is undefined.\n";
    } else {
        cout << "Result: " << a / b << endl;
    }
}

void performSine() {
    double angle = getNumber("Enter angle in radians: ");
    cout << "Result: " << sin(angle) << endl;
}

void performCosine() {
    double angle = getNumber("Enter angle in radians: ");
    cout << "Result: " << cos(angle) << endl;
}

void performTangent() {
    double angle = getNumber("Enter angle in radians: ");
    cout << "Result: " << tan(angle) << endl;
}

void performLogarithm() {
    double value = getNumber("Enter a number: ");
    if (value <= 0) {
        cout << "Error: Logarithm of non-positive number is undefined.\n";
    } else {
        cout << "Result: " << log10(value) << endl;
    }
}

void performNaturalLogarithm() {
    double value = getNumber("Enter a number: ");
    if (value <= 0) {
        cout << "Error: Natural logarithm of non-positive number is undefined.\n";
    } else {
        cout << "Result: " << log(value) << endl;
    }
}

void performPower() {
    double base = getNumber("Enter base number: ");
    double exponent = getNumber("Enter exponent: ");
    cout << "Result: " << pow(base, exponent) << endl;
}

void performSquareRoot() {
    double value = getNumber("Enter a number: ");
    if (value < 0) {
        cout << "Error: Square root of negative number is undefined.\n";
    } else {
        cout << "Result: " << sqrt(value) << endl;
    }
}


