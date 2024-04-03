/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:40:14 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/26 13:52:34 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "Wrong Cat default constructor called." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "Wrong Cat default destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& source) : WrongAnimal() {
    std::cout << "Wrong Cat copy constructor called." << std::endl;
    *this = source;
}

WrongCat &WrongCat::operator=(const WrongCat& source) {
    this->_type = source._type;
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "Meooow! Naaaa?" << std::endl;
}