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

class Fixed {
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& source);
    Fixed& operator=(const Fixed& source);
    int getRawBits(void) const;
    void setRawBits(int const raw);
private:
    static const int    _bits = 8;
    int                 _number;
};


#endif