/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:44:45 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/02 15:32:00 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Character.hpp"
#include "../AMateria.hpp"

Character::Character() : ICharacter() {
    this->_name = "undefined";
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    std::cout << "Character default constructor called." << std::endl;
}

Character::Character(std::string name) : ICharacter() {
    this->_name = name;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    std::cout << "Character name constructor called." << std::endl;
}

Character::~Character() {
    for (int i = 0; i < 4 ; i++)
    {
        if (this ->_inventory[i])
            delete this->_inventory[i];
    }
    std::cout << "Character destructor called." << std::endl;
}

Character::Character(const Character &source) : ICharacter() {
    *this = source;
    std::cout << "Character copy constructor called." << std::endl;
}

Character &Character::operator=(const Character &source) {
    this->_name = source.getName();
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) {
            delete this->_inventory[i];
        }
        if (source._inventory[i]) {
            this->_inventory[i] = source._inventory[i];
        }
        else
            this->_inventory[i] = NULL;
    }
    return (*this);
}


void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            std::cout << "Item " << m->getType() << " is equipped" << std::endl;
            break;
        }
        else if (i == 3)
            std::cout << "inventory full!" << std::endl;
    }
}

void Character::unequip(int idx) {
    if (this->_inventory[idx]) {
        this->_inventory[idx] = NULL;
        std::cout << "item number " << idx << " dropped." << std::endl;
    }
    else
        std::cout << "item number " << idx << " could not be removed" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
    if (idx <= 3 && idx >= 0 && this->_inventory[idx]) {
        std::cout << "\x1B[32m" << this->_name << ": ";
        this->_inventory[idx]->use(target);
    }
    else
        std::cout << "No item to use!" << std::endl;
    std::cout << "\033[0m";
}

std::string const &Character::getName() const {
    return(this->_name);
}