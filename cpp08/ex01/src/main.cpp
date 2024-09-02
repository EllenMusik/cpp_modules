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

    std::cout << "\n" << numbers.longestSpan() << std::endl;
    std::cout << "\n" << numbers.shortestSpan() << std::endl;
    return (0);
}