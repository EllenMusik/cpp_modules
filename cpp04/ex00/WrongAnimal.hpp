/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:40:02 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/26 13:40:02 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

class WrongAnimal {
public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(const WrongAnimal& source);
    WrongAnimal &operator=(const WrongAnimal& source);

    std::string getType() const;
    void makeSound() const;
protected:
    std::string _type;
};

#endif
