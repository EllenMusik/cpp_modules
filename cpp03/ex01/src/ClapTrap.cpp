/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:34:56 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/05 12:53:42 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) , _hitPoints(10) , _energyPoints(10) , _attackDamage(0){
    std::cout << "name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) {
    std::cout << "copy constructor called" << std::endl;
    *this = source;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source) {
    if (this == &source)
        return (*this);
    this->_name = source._name;
    this->_hitPoints = source._hitPoints;
    this->_energyPoints = source._energyPoints;
    this->_attackDamage = source._attackDamage;
    return (*this);
}

void    ClapTrap::attack(const std::string &target) {
    if (this->_energyPoints <= 0) {
        std::cout << "Out of Energy!" << std::endl;
        return ;
    }
    if (this->_hitPoints <= 0){
        std::cout << "Out of hit points!" << std::endl;
        return ;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0){
        std::cout << "Already out of hit points!" << std::endl;
        return ;
    }
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints <= 0) {
        std::cout << "Out of Energy!" << std::endl;
        return ;
    }
    if (this->_hitPoints <= 0){
        std::cout << "Out of hit points!" << std::endl;
        return ;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repaired himself for " << amount << " hit points!" << std::endl;
}

void ClapTrap::showHitPoints() const {
    if (this->_hitPoints <= 0){
        std::cout << "ClapTrap " << this->_name << " Is out of hit points!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::showEnergyPoints() const {
    if (this->_energyPoints <= 0){
        std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points left!" << std::endl;
}