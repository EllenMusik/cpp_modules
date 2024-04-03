/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:52:15 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/01 14:52:15 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Character.hpp"

class ICharacter;

class AMateria {
public:
    AMateria(std::string const &type);
    AMateria();
    virtual ~AMateria();

    AMateria(const AMateria& source);
    AMateria &operator=(const AMateria& source);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
protected:
    std::string _type;
};

#endif