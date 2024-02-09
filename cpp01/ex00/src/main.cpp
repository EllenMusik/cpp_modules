/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:48:14 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/09 14:22:25 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

int main() {
    Zombie* TempPtr;

    randomChump("Karl");
    TempPtr = newZombie("Jana");
    TempPtr->announce();
    delete(TempPtr);
    return (0);
};