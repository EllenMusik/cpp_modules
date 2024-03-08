/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:59:49 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/06 18:59:49 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ClapTrap.hpp"
#include "../ScavTrap.hpp"

int main()
{
    ScavTrap	robot("Robert");
    ClapTrap	oldrobot;

//showing it is not the same robot
    oldrobot.attack("something");

    for (int i = 0; i < 8 ; i++)
        robot.attack("\x1B[33myour mom\033[0m");

    for (int rounds = 0; rounds < 2 ; rounds++)
        robot.beRepaired(20);

    for (int i = 0; i < 2 ; i++)
        robot.attack("\x1B[33myour mom\033[0m");

    robot.guardGate();
    robot.takeDamage(50);
    robot.takeDamage(50);
    for (int i = 0; i < 2 ; i++)
        robot.attack("\x1B[33myour mom\033[0m");
    //the
    robot.guardGate();
    std::cout << "" << std::endl;
    return (0);
}