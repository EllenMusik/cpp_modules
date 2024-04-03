/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:41:34 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/03 11:41:34 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AMateria.hpp"
#include "../Cure.hpp"
#include "../Ice.hpp"
#include "../Character.hpp"
#include "../MateriaSource.hpp"
#include "../IMateriaSource.hpp"
int main()
{
    IMateriaSource *source = new MateriaSource;
    source->learnMateria(new Cure);
    std::cout << "\x1B[35m\nLooking for a non existent Materia\033[0m"<< std::endl;
    AMateria *power;
    power = source->createMateria("random");

    std::cout << "\x1B[35m\nWe now create the character\033[0m" << std::endl;
    ICharacter *Hero = new Character("Wizard");

    std::cout << "\x1B[35m\nLooking for an existing Materia\033[0m"<< std::endl;
    power = source->createMateria("cure");

    std::cout << "\x1B[35m\nThe character now equips a Materia\033[0m" << std::endl;
    Hero->equip(power);
    std::cout << "\x1B[35m\nWe create a target so the character has a target\033[0m"<<std::endl;
    ICharacter *bob = new Character("bob");
    Hero->use(0, *bob);
    std::cout << "\x1B[35m\nUnequip and equip\033[0m"<<std::endl;
    Hero->unequip(0);
    Hero->equip(power);
    std::cout << "\x1B[35m\nLearning new Materia\033[0m"<< std::endl;
    for (int i = 0; i < 3; i++)
    source->learnMateria(new Ice());
    std::cout << "\x1B[35m\nUsing an invalid index\033[0m"<<std::endl;
    Hero->use(1, *bob);
    std::cout << "\x1B[35m\nCreating more Materia and equipping beyond the limit\033[0m"<<std::endl;
    for (int i = 0; i < 4 ; i++){
    power= source->createMateria("ice");
    Hero->equip(power);
    }
    std::cout << "\x1B[35m\nUsing the Materia and trying to use more\033[0m"<<std::endl;
    for (int i = 0; i < 5 ; i++)
    Hero->use(i, *bob);
    std::cout << "\x1B[35m\nChecking with copies and deleting original\033[0m"<<std::endl;
    Character	a("OG");
    Character	b("Fake");
    Character	c("OG Faker");
    a = c;
    c = b;
    std::cout << "We check now for Character a = " << a.getName() << std::endl;
    std::cout << "\x1B[35m\nDeleting\033[0m"<<std::endl;
    delete power;
    delete Hero;
    delete bob;
    delete source;
    return 0;
}

//int main()
//{
//    IMateriaSource* src = new MateriaSource();
//    src->learnMateria(new Ice());
//    src->learnMateria(new Cure());
//    ICharacter* me = new Character("me");
//    AMateria* tmp;
//    tmp = src->createMateria("ice");
//    me->equip(tmp);
//    tmp = src->createMateria("cure");
//    me->equip(tmp);
//    ICharacter* bob = new Character("bob");
//    me->use(0, *bob);
//    me->use(1, *bob);
//    delete bob;
//    delete me;
//    delete src;
//    return 0;
//}