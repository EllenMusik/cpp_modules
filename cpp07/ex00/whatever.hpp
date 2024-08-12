/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:38:34 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/06 16:38:34 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <stdlib.h>
#include <ostream>
#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b) {
    if (a < b)
        return a;
    if (b < a)
        return b;
    if (a == b)
        return b;
    return b;
}

template <typename T>
T max(T a, T b){
    if (a > b)
        return a;
    if (b > a)
        return b;
    else
        return b;
}

#endif
