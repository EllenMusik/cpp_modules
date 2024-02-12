/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:39:57 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/11 15:39:57 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Weapon.hpp"

const std::string& Weapon::getType() {
    //std::string& Temp = this->_type;
    //return (Temp);
    return (this->_type);
}

void Weapon::setType(std::string new_type) {
    this->_type = new_type;
}

Weapon::Weapon(std::string Type) : _type(Type) {
    //std::cout << "new weapon created with type " << this->_type << std::endl;
}

Weapon::~Weapon() {
    //std::cout << "Weapon " << this->_type << " was destroyed!" << std::endl;
}



