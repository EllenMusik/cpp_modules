/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:20:26 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/08 20:20:26 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string.h>
# include <iostream>

class Zombie {
public:
    void announce(void);
    Zombie(std::string name);
    ~Zombie();
private:
    std::string _Name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif


