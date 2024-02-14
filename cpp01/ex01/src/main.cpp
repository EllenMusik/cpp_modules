/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:27:56 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/09 15:27:56 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

int main() {
    Zombie* Zombies;
    int N = 5;

    Zombies = zombieHorde(N, "Greg");
    for (int i = 0; i < N; i++)
        Zombies[i].announce();
    delete[] Zombies;
    return (0);
}