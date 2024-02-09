/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:13:54 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/08 20:15:50 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"


Zombie::Zombie(std::string name) : _Name(name) {
    std::cout << "Zombie " << this->_Name << " was created." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->_Name << " was killed!" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}