/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:46:16 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/01 14:46:16 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AMateria.hpp"

AMateria::AMateria() {
    this->_type = "undefined";
    std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(const std::string &type) {
    this->_type = type;
    std::cout << "AMateria type constructor called." << std::endl;
}

AMateria::AMateria(const AMateria &source) {
    *this = source;
    std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &source) {
    this->_type = source._type;
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called." << std::endl;
}

std::string const &AMateria::getType() const {
    return (this->_type);
}

void AMateria::use(ICharacter& target) {
    std::cout << this->_type << " attacks " << target.getName() << std::endl;
}