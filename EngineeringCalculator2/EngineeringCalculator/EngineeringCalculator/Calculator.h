#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b, bool& ok);
    static double sine(double angle);
    static double cosine(double angle);
    static double tangent(double angle);
    static double logarithm(double value, bool& ok);
    static double naturalLogarithm(double value, bool& ok);
    static double power(double base, double exponent);
    static double squareRoot(double value, bool& ok);
};

#endif // CALCULATOR_H
