/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:05:20 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/06 20:05:20 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*func)(T const &)) {
    for (int i = 0; i < length; i++) {
        func(array[i]);
    }
}


template <typename T>
void print(T const & output) {
    std::cout << "printing: " << output << std::endl;
}

#endif