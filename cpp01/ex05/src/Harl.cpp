/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:56:30 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/13 13:56:30 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Harl.hpp"

#define blue "\e[38;5;25m"
#define lila "\e[38;5;97m"
#define pink "\e[38;5;132m"
#define red  "\e[38;5;124m"
#define reset "\e[0m"

void Harl::complain(std::string level) {
    int index = std::atoi(level.c_str());

    void (Harl::*functionPointers[4])(void);
    functionPointers[0] = &Harl::debug;
    functionPointers[1] = &Harl::info;
    functionPointers[2] = &Harl::warning;
    functionPointers[3] = &Harl::error;

    index -= 1;
    if (index >= 0 && index <= 3) {
        (this->*functionPointers[index])();
    }
    else {
        std::cout << "invalid input." << std::endl;
    }
}

void Harl::debug() {
    std::cout << blue << "If you want to debug, just look at the code. It's not that hard, I'm sure you can do it on your own for once :)" << reset << std::endl;
}

void Harl::info() {
    std::cout << lila << "Come one, at least try! You are frustrated? Just don't be, there is no reason for that, others have it way worse you know :)" << reset << std::endl;
}

void Harl::warning () {
    std::cout << pink << "Oh okay? Ehm, are you sure about this? It looks... interesting. No offence tho, I'm just saying :)" << reset << std::endl;
}

void Harl::error () {
    std::cout << red << "Hahaha, that's a good one! Wait, you are serious about this? It was not a joke? Yeah I honestly could not tell :)" << reset << std::endl;
}