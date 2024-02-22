/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:18:10 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/14 13:18:10 by esteiner         ###   ########.fr       */
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
    Fixed&  operator=(const Fixed& source);
    float   toFloat(void) const;
    int     toInt(void) const;
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
private:
    static const int    _bits = 8;
    int                 _fixed_point_number;
};

Fixed&  operator<<(std::ostream& os, Fixed const &fixed);

#endif