/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:48:35 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/01 15:48:35 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cure.hpp"

Cure::Cure() : AMateria() {
    this->_type = "cure";
    std::cout << "Cure default constructor called." << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure destructor called." << std::endl;
}

Cure::Cure(const Cure &source) : AMateria() {
    *this = source;
    std::cout << "Cure copy constructor called." << std::endl;
}

Cure &Cure::operator=(const Cure &source) {
    this->_type = source._type;
    return (*this);
}

AMateria* Cure::clone() const {
    AMateria *clone = new Cure();
    return (clone);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}