/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:03:55 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/11 16:03:55 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "../easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const char* e) {
        std::cerr << e << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const char* e) {
        std::cerr << e << std::endl;
    }

    return 0;
}