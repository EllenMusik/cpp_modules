/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:39:35 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/11 15:39:35 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
    void attack();
    void setWeapon(Weapon& newWeapon);
    HumanB(std::string name);
    ~HumanB();
private:
    std::string _Name;
    Weapon* _myWeapon;
};


#endif