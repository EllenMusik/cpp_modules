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
    Animal *array[6];
    for (int i = 0; i < 3; i++) {
        array[i] = new Cat();

        std::cout << "" << std::endl;

        array[i + 3] = new Dog();

        std::cout << "" << std::endl;
    }
    std::cout << "\ntest" << std::endl;
    std::cout << "" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        delete array[i];

        std::cout << "" << std::endl;

        delete array[i + 3];

        std::cout << "" << std::endl;
    }

    Cat *a = new Cat;
    Cat *b = new Cat;
    Cat *c = new Cat;

    for(int ret = 0; ret < 10 ; ret++)
        a->setIdea("Let's think of something");
    for(int i = 0 ; i < 10  ; i++)
        b->setIdea("Random thoughts");
    for(int i = 0 ; i < 10 ; i++)
        c->setIdea("This should never show up");
    *c = *a;	//to prove we don't have a shallow copy we have C=A and change the value of A
    *a = *b;	//therefore C isn't just a pointer but has it's own deep copy independent from A;

    c->showBrain();
    a->showBrain();
    std::cout << "" << std::endl;
    delete a;
    std::cout << "" << std::endl;
    delete b;
    std::cout << "" << std::endl;
    delete c;
    std::cout << "" << std::endl;
    return (0);
}
