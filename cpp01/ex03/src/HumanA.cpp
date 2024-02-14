/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:39:15 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/11 15:39:15 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& my_weapon) : _Name(name), _myWeapon(my_weapon) {
    //std::cout << "HumanA " << this->_Name << " was created ";
    //std::cout << "with the Weapon " << this->_myWeapon->getType() << std::endl;
}

HumanA::~HumanA() {
    //std::cout << "HumanA " << this->_Name << " was destroyed." << std::endl;
}

void HumanA::attack() {
    std::cout << this->_Name << " attacks wit their weapon " << this->_myWeapon->getType() << std::endl;
}