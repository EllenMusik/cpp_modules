/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:38:23 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/11 15:38:23 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string.h>
#include <iostream>
#include <sstream>

class Weapon {
public:
    const std::string& getType();
    void setType(std::string new_type);
    Weapon(std::string Type);
    ~Weapon();
private:
    std::string _type;
};

#endif