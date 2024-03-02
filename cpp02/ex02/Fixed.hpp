/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:18:10 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/24 18:17:55 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>

class Fixed {
public:
    Fixed();
    ~Fixed();
    Fixed(const int number);
    Fixed(const float float_number);
    Fixed(const Fixed& source);
    float   toFloat(void) const;
    int     toInt(void) const;
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    Fixed&  operator=(const Fixed& source);

    Fixed  operator+(const Fixed& source);
    Fixed  operator-(const Fixed& source);
    Fixed  operator*(const Fixed& source);
    Fixed  operator/(const Fixed& source);

    bool  operator==(const Fixed& source);
    bool  operator<(const Fixed& source);
    bool  operator>(const Fixed& source);
    bool  operator<=(const Fixed& source);
    bool  operator>=(const Fixed& source);
    bool  operator!=(const Fixed& source);

    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);

    static Fixed &max(Fixed &lhs, Fixed &rhs);
    static Fixed const &max(const Fixed &lhs , const Fixed &rhs);
    static Fixed &min(Fixed &lhs, Fixed &rhs);
    static Fixed const &min(const Fixed &lhs , const Fixed &rhs);
private:
    static const int    _bits = 8;
    int              _fixed_point_number;
};

std::ostream&  operator<<(std::ostream& os, Fixed const &fixed);

#endif
