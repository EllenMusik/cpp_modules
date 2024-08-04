/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:55:05 by esteiner          #+#    #+#             */
/*   Updated: 2024/07/27 15:56:01 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Default constructor called (hopefully not lol)" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    if (this == &src)
        return *this;
    return *this;
}

void ScalarConverter::convert(const std::string &input) {
    std::cout << TURQUOISE << "convert " << input << RST << std::endl;
    std::cout << PASTEL_PINK;

    long integer;
    float floating;
    double doubling;
    char character;
    char *endptr;

    if (input.length() == 0) {
        std::cout << PINK  << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        std::cout << RST << std::endl;
        return;
    }
    if (input.length() == 1) {
        character = input[0];
        integer = static_cast<int>(character);
        floating = static_cast<float>(character);
        doubling = static_cast<double>(character);
        std::cout << "char: '" << character << "'" << std::endl;
        std::cout << "int: " << integer << std::endl;
        std::cout << "float: " << integer << ".0f" << std::endl;
        std::cout << "double: " << integer << ".0" << std::endl;
        std::cout << RST << std::endl;
        return;

    }
    // Handle special float and double literals
    if (input == "-inff" || input == "+inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "nan") {
        std::cout << PINK << "char: impossible" << std::endl;
        std::cout << "int: impossible" << PASTEL_PINK << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
        std::cout << RST << std::endl;
        return;
    }

    integer = std::strtol(input.c_str(), &endptr, 10);
    if (integer < INT_MIN || integer > INT_MAX || input.length() > 10 || (endptr != NULL && *endptr != '\0' && *endptr != 'f' && *endptr != '.')) {
        std::cout << PINK << "char: impossible" << std::endl;
        std::cout << "int: impossible" << PASTEL_PINK << std::endl;
    }
    else if (integer >= 32 && integer <= 126) {
        character = static_cast<char>(integer);
        std::cout << "char: '" << character << "'" << std::endl;
        std::cout << "int: " << integer << std::endl;
    }
    else{
        std::cout << LAVENDER << "char: Non displayable" << PASTEL_PINK << std::endl;
        std::cout << "int: " << integer << std::endl;
    }

    floating = std::strtof(input.c_str(), &endptr);
    if (endptr != NULL && *endptr != '\0' && *endptr != 'f') {
        std::cout << PINK  << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        std::cout << RST << std::endl;
        return;
    }
    doubling = std::strtod(input.c_str(), NULL);

    if (floating == static_cast<float>(integer) && floating == static_cast<float>(doubling)) {
        std::cout << "float: " << floating << ".0f" << std::endl;
        std::cout << "double: " << doubling << ".0" << std::endl;
    }
    else {
        std::cout << "float: " << floating << "f" << std::endl;
        std::cout << "double: " << doubling << std::endl;
    }

    std::cout << RST << std::endl;
    return ;
}