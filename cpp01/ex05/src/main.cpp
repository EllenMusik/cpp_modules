/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:54:25 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/13 13:54:25 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Harl.hpp"

int main()
{
    Harl newHarl;
    std::string input;

    std::cout << "Type number between 0 and 4:\n0 = exit\n1 = debug\n2 = info\n3 = warning\n4 = error\n" << std::endl;
    while (1) {
        std::cin >> input;
        if (input == "0") {
            return (0);
        }
        newHarl.complain(input);
    }
    return (0);
}