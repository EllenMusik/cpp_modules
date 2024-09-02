/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:24:14 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/11 17:24:14 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Span.hpp"
#include <vector>

int main() {
    Span numbers(5);

    numbers.addNumber(-10);
    numbers.addNumber(-5);
    numbers.addNumber(-1);
    numbers.addNumber(7);
    numbers.addNumber(20);
    try {
        numbers.addNumber(200);
    }
    catch (const std::runtime_error& e) {
        std::cout << RED << e.what() << RST << std::endl;
    }
    numbers.print_span();

    std::cout << LAVENDER << "\n" << numbers.longestSpan() << RST << std::endl;
    std::cout << "\n" << numbers.shortestSpan() << "\n-------" << std::endl;

    Span test(7);

    test.addNumber(14);
    test.addNumber(12);

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);

    try {
        test.addRange(vec.begin(), vec.end());  // adding the range of Numbers
    }
    catch (const std::runtime_error& e) {
        std::cout << RED << e.what() << RST << std::endl;
    }
    test.print_span();
    std::cout << LAVENDER << "\n" << test.longestSpan() << RST << std::endl;
    return (0);
}