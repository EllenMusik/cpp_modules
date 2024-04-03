/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:00:14 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/26 14:00:14 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../animal.hpp"
#include "../cat.hpp"
#include "../dog.hpp"
#include "../Brain.hpp"

int main()
{
    //const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    //std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    //meta->makeSound();
    delete j;
    delete i;
    //delete meta;
}
