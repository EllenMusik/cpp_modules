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

Fixed::Fixed() : _fixed_point_number(0) {
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : _fixed_point_number(0) {
    std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _fixed_point_number(0) {
    std::cout << "float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source) {
    std::cout << "copy constructor called" << std::endl;
    *this = source;
}

Fixed &Fixed::operator=(Fixed const &source) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &source)
        return (*this);
    this->_fixed_point_number = source.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixed_point_number);
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixed_point_number =  raw;
}

float Fixed::toFloat() const {
    return ((float)this->_fixed_point_number / (float)(1 << Fixed::_bits));
}

int Fixed::toInt() const {
    return (this->_fixed_point_number >> Fixed::_bits);
}

std::ostream  &operator<<(std::ostream &os, Fixed const &fixed) {
    return (os << fixed.toFloat());
}