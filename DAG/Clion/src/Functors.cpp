// #include "../include/Functors.h"
//
// #include <iostream>
//
// int add(const std::vector<int>& inputs) {
//     std::cout << "add() call" << std::endl;
//     return inputs[0] + inputs[1];
// }
//
// int square(const std::vector<int> &inputs) {
//     std::cout << "square() call" << std::endl;
//     return inputs[0] * inputs[0];
// }
//
// int find_max(const std::vector<int> &inputs) {
//     std::cout << "find_max() call" << std::endl;
//     return *std::max_element(inputs.begin(), inputs.end());
// }
//
// int subtract(const std::vector<int> &inputs) {
//     std::cout << "subtract() call" << std::endl;
//     return inputs[0] - inputs[1];
// }
//
// int multiply(const std::vector<int> &inputs) {
//     std::cout << "multiply() call" << std::endl;
//     return inputs[0] * inputs[1];
// }
//
// int divide(const std::vector<int> &inputs) {
//     std::cout << "divide() call" << std::endl;
//     return inputs[0] / inputs[1];
// }
//
// int constant(const std::vector<int> &inputs) {
//     std::cout << "constant() call" << std::endl;
//     return inputs[0];
// }
//
//
// std::function<int(const std::vector<int>&)> getFunction(int funcId) {
//     switch (funcId) {
//         case 0: return add;
//         case 1: return square;
//         case 2: return find_max;
//         case 3: return subtract;
//         case 4: return multiply;
//         case 5: return divide;
//         case 6: return constant;
//         default: throw std::invalid_argument("invalid_argument");
//     }
// }
//
// void printFunctionOptions() {
//     std::cout << "--Function Option--\n";
//     std::cout << "0 : add\n";
//     std::cout << "1 : square\n";
//     std::cout << "2 : find_max\n";
//     std::cout << "3 : subtract\n";
//     std::cout << "4 : multiply\n";
//     std::cout << "5 : divide\n";
//     std::cout << "6 : constant\n";
// }