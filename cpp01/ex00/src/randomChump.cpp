/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:49:56 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/07 16:49:56 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

# include <iostream>

void randomChump(std::string name) {
    Zombie newZombie(name);

    newZombie.announce();
    return;
}