/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:59:59 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/24 18:59:59 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << "\n" << a.min(a, b) << std::endl;
    std::cout << "\n" << a.min(a, b) << std::endl;
    return 0;
}