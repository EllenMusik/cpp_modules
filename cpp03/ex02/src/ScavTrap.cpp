/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:01:51 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/08 17:51:49 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ClapTrap.hpp"
#include "../ScavTrap.hpp"

void ScavTrap::guardGate() {
 std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap() {
    this->_name = "ScavTrap";
    this->_energyPoints = 50;
    this->_hitPoints = 100;
    this->_attackDamage = 20;
    std::cout << "ScavTrap standard constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {

    this->_name = name;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
    this->_attackDamage = 20;
    std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = source;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& source) {
    if (this == &source)
        return (*this);
    this->_name = source._name;
    this->_hitPoints = source._hitPoints;
    this->_energyPoints = source._energyPoints;
    this->_attackDamage = source._attackDamage;
    return (*this);
}
