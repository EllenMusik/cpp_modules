/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:38:42 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/10 16:38:42 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <iostream>
# include <sstream>

int main() {
    std::string message = "HI THIS IS BRIAN";
    std::string* stringPTR = &message;
    std::string& stringREF = message;

    std::cout << "Address of message:   " << &message << std::endl;
    std::cout << "Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << "value of message:              " << message << std::endl;
    std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
}