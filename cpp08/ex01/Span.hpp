/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:24:14 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/11 17:24:14 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <stdlib.h>
#include <algorithm>
#include "colors.hpp"

class Span {
public:
    Span();
    Span(unsigned int N);
    ~Span();
    Span(const Span &src);
    Span &operator=(const Span &src);

    void addNumber(int nbr);
    void print_span() const;

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end)  {
        for (InputIterator it = begin; it != end; ++it) {
            if (_curr_elements == _max_elements) {
                throw std::runtime_error("Cannot add Number: Max capacity of stored numbers reached.");
            }
            _int_array.insert(*it);
            _curr_elements++;
        }
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

private:
    unsigned int _max_elements;
    unsigned int _curr_elements;

    std::set<int> _int_array;
};


#endif