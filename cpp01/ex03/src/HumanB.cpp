/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:39:23 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/11 15:39:23 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HumanB.hpp"

HumanB::HumanB(std::string name) : _Name(name) {
    //std::cout << "HumanB " << this->_Name << " was created."<< std::endl;
}

HumanB::~HumanB() {
    //std::cout << "HumanB " << this->_Name << " was destroyed." << std::endl;
}

void HumanB::attack() {
    std::cout << this->_Name << " attacks wit their weapon " << this->_myWeapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon) {
    this->_myWeapon = &newWeapon;
}