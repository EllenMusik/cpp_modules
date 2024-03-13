/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:09:38 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/11 18:09:38 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FragTrap.hpp"

void FragTrap::highFivesGuys(void) {
    std::cout << this->_name << ": high five? please?" << std::endl;
}

FragTrap::FragTrap() : ClapTrap() {
    this->_name = "FragTrap";
    this->_energyPoints = 100;
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap standard constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap() {

    this->_name = name;
    this->_energyPoints = 100;
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = source;
}

FragTrap& FragTrap::operator=(FragTrap const& source) {
    std::cout << "FragTrap = operator overload called" << std::endl;
    if (this == &source)
        return (*this);
    this->_name = source._name;
    this->_hitPoints = source._hitPoints;
    this->_energyPoints = source._energyPoints;
    this->_attackDamage = source._attackDamage;
    return (*this);
}