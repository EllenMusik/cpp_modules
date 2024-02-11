/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:28:49 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/09 15:28:49 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string.h>
# include <iostream>
#include <sstream>

class Zombie {
public:
    void announce(void);
    void set_Name(std::string name);
    Zombie();
    ~Zombie();
private:
    std::string _Name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
