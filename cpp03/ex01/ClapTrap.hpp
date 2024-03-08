/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:34:26 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/05 12:47:31 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

class ClapTrap {
public:
    ClapTrap();
    ~ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& source);
    ClapTrap &operator=(const ClapTrap &source);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void showHitPoints() const;
    void showEnergyPoints() const;
private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;
};

#endif