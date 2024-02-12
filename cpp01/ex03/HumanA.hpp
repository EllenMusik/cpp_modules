/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:39:02 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/11 15:39:02 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
    void attack();
    HumanA(std::string name, Weapon& my_weapon);
    ~HumanA();
private:
    std::string _Name;
    Weapon* _myWeapon;
};


#endif