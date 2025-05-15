#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) {
    double value = 0.0;
    std::string input = literal;

    // Vérifier si c’est un littéral de type char, ex : 'a'
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        char c = literal[1];
        value = static_cast<double>(c);
    }
    // Pseudo-littéraux float (nanf, +inff, -inff)
    else if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        if (literal == "nanf")
            value = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            value = std::numeric_limits<float>::infinity();
        else
            value = -std::numeric_limits<float>::infinity();
    }
    // Pseudo-littéraux double (nan, +inf, -inf)
    else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        if (literal == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            value = std::numeric_limits<double>::infinity();
        else
            value = -std::numeric_limits<double>::infinity();
    }
    else {
        // Vérifie si la fin est un 'f' → float
        if (literal.back() == 'f' && literal.find('.') != std::string::npos) {
            input = literal.substr(0, literal.length() - 1);  // enlever le 'f'
        }

        char* end;
        value = std::strtod(input.c_str(), &end);

        if (*end != '\0') {
            std::cout << "invalid input format." << std::endl;
            return;
        }
    }

    // CHAR
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    // INT
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) ||
        value > static_cast<double>(std::numeric_limits<int>::max()) ||
        value < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    // FLOAT
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f" << std::endl;

    // DOUBLE
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1)
              << static_cast<double>(value) << std::endl;
}

// Constructeurs/désallocateurs privés
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}