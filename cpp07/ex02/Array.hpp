/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:49:09 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/07 16:49:09 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdlib.h>

//#include "src/Array.tpp"

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int i);
    Array(const Array &src);
    Array &operator=(const Array &src);
    ~Array();

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

    unsigned int size() const;
private:
    unsigned int _size;
    T *_array;
};

#include "Array.tpp"

#endif