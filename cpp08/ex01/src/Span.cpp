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

#include "../Span.hpp"

Span::Span() {
    _max_elements = 0;
    _curr_elements = 0;
}

Span::Span(unsigned int N) {
    _max_elements = N;
    _curr_elements = 0;
}

Span::Span(const Span &src) {
    *this = src;
}

Span &Span::operator=(const Span &src) {
    _max_elements = src._max_elements;
    _curr_elements = src._curr_elements;

    std::set<int>::const_iterator it = src._int_array.begin();

    for (unsigned int i = 0; i < _curr_elements; i++){
        _int_array.insert(*it);
        it++;
    }
    return (*this);
}

Span::~Span() {
}

void Span::addNumber(int nbr){
    if (_curr_elements == _max_elements){
        throw std::runtime_error("Cannot add Number: Max capacity of stored numbers reached.");
    }
    _int_array.insert(nbr);
    _curr_elements++;
    std::cout << PASTEL_GREEN << nbr << RST << std::endl;
}

void Span::print_span() const {
    for (std::set<int>::iterator it = _int_array.begin(); it != _int_array.end(); ++it) {
        std::cout << PASTEL_RED << *it << RST << std::endl;
    }
}


unsigned int Span::longestSpan() const {
    if (_int_array.empty() || _curr_elements == 1) {
        throw std::runtime_error("No span can be found");
    }
    unsigned int span_size;
    //std::cout << *_int_array.rbegin() << " " << *_int_array.begin() << std::endl;
    span_size = abs(*_int_array.rbegin() - *_int_array.begin());
    return (span_size);
}

unsigned int Span::shortestSpan() const {
    unsigned int shortest_span;

    if (_int_array.empty() ||  _curr_elements == 1) {
        throw std::runtime_error("No span can be found");
    }
    std::set<int>::iterator it = _int_array.begin();
    std::set<int>::iterator iter = it++;
    shortest_span = abs(*it - *iter);
    for (it = _int_array.begin(); it != _int_array.end(); ++it) {
        iter = it;
        ++iter;
        if (iter == _int_array.end())
            continue;
        if (abs(*iter - *it) < shortest_span)
            shortest_span = abs(*iter - *it);
    }
    return (shortest_span);
}

