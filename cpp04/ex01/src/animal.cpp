/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:28:56 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/13 14:28:56 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../animal.hpp"

#include "../cat.hpp"

Animal::Animal() {
    this->_type = "undefined";
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal default destructor called." << std::endl;
}

Animal::Animal(const Animal& source) {
    std::cout << "Animal copy constructor called." << std::endl;
    *this = source;
}

Animal &Animal::operator=(const Animal& source) {
    this->_type = source._type;
    return (*this);
}

void Animal::makeSound() const {
    std::cout << "*Unrecognizable and unspecific animal noises*" << std::endl;
}

std::string Animal::getType() const {
    return (this->_type);
}