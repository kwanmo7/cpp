#include "Calculator.h"
#include <cmath>

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b, bool& ok) {
    if (b == 0) {
        ok = false;
        return 0;
    }
    ok = true;
    return a / b;
}

double Calculator::sine(double angle) {
    return sin(angle);
}

double Calculator::cosine(double angle) {
    return cos(angle);
}

double Calculator::tangent(double angle) {
    return tan(angle);
}

double Calculator::logarithm(double value, bool& ok) {
    if (value <= 0) {
        ok = false;
        return 0;
    }
    ok = true;
    return log10(value);
}

double Calculator::naturalLogarithm(double value, bool& ok) {
    if (value <= 0) {
        ok = false;
        return 0;
    }
    ok = true;
    return log(value);
}

double Calculator::power(double base, double exponent) {
    return pow(base, exponent);
}

double Calculator::squareRoot(double value, bool& ok) {
    if (value < 0) {
        ok = false;
        return 0;
    }
    ok = true;
    return sqrt(value);
}
