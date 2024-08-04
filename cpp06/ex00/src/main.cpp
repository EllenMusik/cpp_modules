/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:37:02 by esteiner          #+#    #+#             */
/*   Updated: 2024/07/27 15:37:02 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ScalarConverter.hpp"

int main() {
    //ScalarConverter test; // <-- This line will (and should) not compile

    ScalarConverter::convert("42f");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("42");
    ScalarConverter::convert(" 42");
    ScalarConverter::convert("12346");
    ScalarConverter::convert("12345678901234567890");
    ScalarConverter::convert("-4567");
    ScalarConverter::convert("56");
    ScalarConverter::convert("0");
    ScalarConverter::convert("0.0");
    std::cout << std::endl;
    ScalarConverter::convert("a");
    ScalarConverter::convert("~");
    ScalarConverter::convert("hello123naaa");
    ScalarConverter::convert("123.456.789");
    ScalarConverter::convert("5678naaa");
    ScalarConverter::convert("33.4567");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("-inff");
    return 0;
}