/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:29:04 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/13 14:29:04 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cat.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat default destructor called." << std::endl;
}

Cat::Cat(const Cat& source) : Animal() {
    std::cout << "Cat copy constructor called." << std::endl;
    *this = source;
}

Cat &Cat::operator=(const Cat& source) {
    this->_type = source._type;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meooow! Naaaa?" << std::endl;
}