/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:20:18 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/02 18:20:18 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../colors.hpp"
#include "../Base.hpp"
#include "../A.hpp"
#include "../B.hpp"
#include "../C.hpp"
#include <stdlib.h>

Base* generate(void) {
    static bool srandCalled = false;

    if (!srandCalled) {
        srand(time(NULL));
        srandCalled = true;
    }
    //srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) {
        std::cout << PASTEL_RED << "A was created" << RST << std::endl;
        return (new A());
    }
    else if (random == 1) {
        std::cout << TURQUOISE << "B was created" << RST << std::endl;
        return (new B());
    }
    else {
        std::cout << PASTEL_YELLOW << "C was created" << RST << std::endl;
        return (new C());
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << RED << "*A identified" << RST << std::endl;
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << TEAL << "*B identified" << RST << std::endl;
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << YELLOW2 << "*C identified" << RST << std::endl;
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << RED << "&A identified" << RST << std::endl;
        return;
    }
    catch (const std::exception& e) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << TEAL << "&B identified" << RST << std::endl;
        return;
    }
    catch (const std::exception& e) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << YELLOW2 << "&C identified" << RST << std::endl;
        return;
    }
    catch (const std::exception& e) {
        std::cout << BRIGHT_ORANGE << "Error: unknown class" << RST << std::endl;
    }
}