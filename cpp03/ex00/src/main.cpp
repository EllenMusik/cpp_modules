/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:33:41 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/02 18:33:41 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ClapTrap.hpp"

int main() {
    ClapTrap Bot1("BotA");
    ClapTrap Bot2("BotB");

    Bot1.attack("Air");
    Bot2.attack("Nothing");

    Bot1.takeDamage(5);
    Bot1.takeDamage(5);

    Bot2.showHitPoints();
    Bot1.showHitPoints();

    Bot1.beRepaired(3);

    Bot1.showHitPoints();
    Bot1.showEnergyPoints();
    Bot2.showEnergyPoints();
    return (0);
}
