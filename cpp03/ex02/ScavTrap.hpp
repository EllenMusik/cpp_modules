/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:01:39 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/06 19:01:39 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ~ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const& source);
    ScavTrap& operator=(ScavTrap const& source);

    void    guardGate();
};

#endif
