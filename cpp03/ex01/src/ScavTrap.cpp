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
 std::cout << "ScavTrap" << this->_name << "is now in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {

}

ScavTrap::ScavTrap(std::string name) {

}

ScavTrap::ScavTrap(const ScavTrap &source) {

}

ScavTrap& ScavTrap::operator=(ScavTrap const& source) {

}
