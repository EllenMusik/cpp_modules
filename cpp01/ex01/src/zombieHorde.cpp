/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:27:38 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/09 15:43:27 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* Horde;
    int     i = 0;

    Horde = new Zombie[N];
    while (i < N)
    {
        Horde[i].set_Name(name);
        i++;
    }
    return (Horde);
}