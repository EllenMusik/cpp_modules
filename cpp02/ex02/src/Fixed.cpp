/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:18:18 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/24 18:44:00 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"

Fixed::Fixed() : _fixed_point_number(0) {
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
    std::cout << "int constructor called" << std::endl;
    this->_fixed_point_number = number << this->_bits;
}

Fixed::Fixed(const float number) {
    std::cout << "float constructor called" << std::endl;
    this->_fixed_point_number = roundf(number * (1 << this->_bits));
}

Fixed::Fixed(const Fixed& source) {
   // std::cout << "copy constructor called" << std::endl;
    *this = source;
}

Fixed &Fixed::operator=(Fixed const &source) {
   // std::cout << "Copy assignment operator called" << std::endl;
    if (this == &source)
        return (*this);
    this->_fixed_point_number = source.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
   // std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixed_point_number);
}

void Fixed::setRawBits(const int raw) {
  //  std::cout << "setRawBits member function called" << std::endl;
    this->_fixed_point_number = raw;
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




//calculations


Fixed Fixed::operator+(const Fixed& source) {
    return (this->toFloat() + source.toFloat());
}

Fixed Fixed::operator-(const Fixed& source) {
    return (this->toFloat() - source.toFloat());
}

Fixed Fixed::operator*(const Fixed& source) {
    return (this->toFloat() * source.toFloat());
}

Fixed Fixed::operator/(const Fixed& source) {
    return (this->toFloat() / source.toFloat());
}



// comparisons

bool  Fixed::operator<(const Fixed& source) {
    if (this->getRawBits() < source.getRawBits())
        return true;
    else
        return false;
}

bool  Fixed::operator>(const Fixed& source) {
    if (this->getRawBits() > source.getRawBits())
        return true;
    else
        return false;
}

bool  Fixed::operator==(const Fixed& source) {
    if (this->getRawBits() == source.getRawBits())
        return true;
    else
        return false;
}

bool  Fixed::operator<=(const Fixed& source) {
    if (this->getRawBits() <= source.getRawBits())
        return true;
    else
        return false;
}

bool  Fixed::operator>=(const Fixed& source) {
    if (this->getRawBits() >= source.getRawBits())
        return true;
    else
        return false;
}


bool  Fixed::operator!=(const Fixed& source) {
    if (this->getRawBits() == source.getRawBits())
        return false;
    else
        return true;
}



//incrementation/decrementation

Fixed& Fixed::operator++(void) {
    this->_fixed_point_number++;
    return (*this);
}

Fixed& Fixed::operator--(void) {
    this->_fixed_point_number--;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed	tmp(*this);
    this->_fixed_point_number++;
    return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed	tmp(*this);
    this->_fixed_point_number--;
    return tmp;
}




Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
    if (lhs > rhs)
        return (lhs);
    else
        return (rhs);
}

Fixed const & Fixed::max (Fixed const &lhs , Fixed const &rhs) {
    if (lhs.getRawBits() < rhs.getRawBits())
        return (rhs);
    else
        return (lhs);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
    if (lhs < rhs)
        return (lhs);
    else
        return (rhs);
}

Fixed const &Fixed::min(const Fixed &lhs , const Fixed &rhs) {
    if (lhs.getRawBits() < rhs.getRawBits())
        return (lhs);
    else
        return (rhs);
}