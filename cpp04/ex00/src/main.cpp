/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:18:01 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/26 13:50:30 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../animal.hpp"
#include "../cat.hpp"
#include "../dog.hpp"
#include "../WrongAnimal.hpp"
#include "../WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;

    std::cout << "" << std::endl;

    const WrongAnimal* falseMeta = new WrongAnimal();
    const WrongAnimal* falseCat = new WrongCat();
    std::cout << falseMeta->getType() << " " << std::endl;
    std::cout << falseCat->getType() << " " << std::endl;
    falseMeta->makeSound();
    falseCat->makeSound();
    delete falseCat;
    delete falseMeta;

    return 0;
}