/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:31:21 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/13 14:31:32 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    this->_brain = new Brain;
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog default destructor called." << std::endl;
}

Dog::Dog(const Dog& source) : Animal() {
    std::cout << "Dog copy constructor called." << std::endl;
    *this = source;
}

Dog &Dog::operator=(const Dog& source) {
    this->_type = source._type;
    this->_brain = source._brain;
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Wau! Woof?" << std::endl;
}