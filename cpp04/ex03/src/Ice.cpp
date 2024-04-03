/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:46:11 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/01 15:46:11 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ice.hpp"

Ice::Ice() : AMateria() {
    this->_type = "ice";
    std::cout << "Ice default constructor called." << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice destructor called." << std::endl;
}

Ice::Ice(const Ice &source)  : AMateria() {
    *this = source;
    std::cout << "Ice copy constructor called." << std::endl;
}

Ice &Ice::operator=(const Ice &source) {
    this->_type = source._type;
    return (*this);
}

AMateria* Ice::clone() const {
    AMateria *clone = new Ice();
    return (clone);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}