#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
    long double left;
    long double right;
    char operation;

    if (!(std::cin >> left >> operation >> right)) {
        std::cerr << "Invalid input. Enter an expression such as 1.5 + 2.3.\n";
        return 1;
    }

    std::cin >> std::ws;
    if (std::cin.peek() != std::char_traits<char>::eof()) {
        std::cerr << "Invalid input. Enter exactly one expression.\n";
        return 1;
    }

    if (!std::isfinite(left) || !std::isfinite(right)) {
        std::cerr << "Operands must be finite numbers.\n";
        return 1;
    }

    long double result;
    switch (operation) {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        if (right == 0) {
            std::cerr << "Division by zero is not allowed.\n";
            return 1;
        }
        result = left / right;
        break;
    default:
        std::cerr << "Unsupported operator. Use +, -, *, or /.\n";
        return 1;
    }

    if (!std::isfinite(result)) {
        std::cerr << "The result is outside the supported numeric range.\n";
        return 1;
    }

    std::cout << std::setprecision(15) << result << '\n';
    return 0;
}