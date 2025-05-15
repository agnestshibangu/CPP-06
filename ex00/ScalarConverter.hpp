#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iomanip> 
#include <cmath>

#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    // Méthode statique unique pour effectuer la conversion
    static void convert(const std::string& literal);

private:
    // Constructeur, destructeur, opérateur de copie privés pour empêcher l'instanciation
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
};

#endif // SCALARCONVERTER_HPP
