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

#include "../Brain.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat default destructor called." << std::endl;
}

Cat::Cat(const Cat& source) : Animal() {
    std::cout << "Cat copy constructor called." << std::endl;
    *this = source;
}

Cat &Cat::operator=(const Cat& source) {
    std::cout << "Cat copy assignment operator called." << std::endl;
    this->_type = source._type;
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = *source._brain;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meooow! Naaaa?" << std::endl;
}

void Cat::setIdea(std::string idea) {
    this->_brain->addIdea(idea);
}

void Cat::showBrain(void) {
    this->_brain->showIdeas();
}