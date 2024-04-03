/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:41:07 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/26 13:41:07 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../WrongAnimal.hpp"

#include "../WrongCat.hpp"

WrongAnimal::WrongAnimal() {
    this->_type = "undefined";
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal default destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source) {
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    *this = source;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& source) {
    this->_type = source._type;
    return (*this);
}

void WrongAnimal::makeSound() const {
    std::cout << "*Unrecognizable and unspecific Wrong animal noises*" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->_type);
}
