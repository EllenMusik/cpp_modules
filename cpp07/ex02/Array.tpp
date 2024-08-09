/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:04:36 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/08 16:25:54 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../Array.hpp"
#include "colors.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(NULL) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]()) {
}


template <typename T>
Array<T>::Array(const Array &src) : _array(NULL) {
    *this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
    if (this != &src)
    {
        delete[] (_array);
        _size = src.size();
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = src._array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(){
    delete[] (_array);
    std::cout << BRIGHT_BLACK << "array was freed." << RST << std::endl;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const {
    return (_size);
}
