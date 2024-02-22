/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:18:18 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/14 13:18:18 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"

Fixed::Fixed() : _number(0) {
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source) {
    std::cout << "copy constructor called" << std::endl;
    *this = source;
}

Fixed &Fixed::operator=(Fixed const &source) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &source)
        return (*this);
    this->_number = source.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_number);
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_number =  raw;
}