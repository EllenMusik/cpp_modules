/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:28:23 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/13 14:28:23 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Animal {
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& source);
    Animal &operator=(const Animal& source);

    std::string getType() const;
    virtual void makeSound() const;
protected:
    std::string _type;
};

#endif
