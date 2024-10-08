/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:48:49 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/06 19:48:49 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../iter.hpp"

int main()
{
    int intarray[3] = {1, 2, 3};

    ::iter(intarray, 3, print<int>);

    std::string strarray[4] = {"NAaaaa", "Guten Tag", "I love Cats", "last Element"};

    ::iter(strarray, 4, print<std::string>);
}