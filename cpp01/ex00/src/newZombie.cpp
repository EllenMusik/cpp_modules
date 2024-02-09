/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:15:40 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/08 20:15:40 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie* zombiePtr;

    std::cout << "debug print" << std::endl;
    zombiePtr = new Zombie(name);
    return (zombiePtr);
}