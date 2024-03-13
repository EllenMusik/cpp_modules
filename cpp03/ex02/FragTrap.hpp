/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:47:15 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/11 17:47:15 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTRAP_HPP
#define FRACTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap();
    ~FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const& source);
    FragTrap& operator=(FragTrap const& source);

    void highFivesGuys(void);
};

#endif