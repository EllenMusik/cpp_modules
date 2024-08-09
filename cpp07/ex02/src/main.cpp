/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:47:46 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/07 16:47:46 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../Array.hpp"
#include "../colors.hpp"

int main(){
    {
        Array<std::string> words(2);

        words[0] = "Rolls";
        words[1] = "Cinnamon";

        std::cout << PINK << words[1] << " " << words[0] << RST << std::endl;

        try {
            std::cout << PINK << words[3] << RST << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << PASTEL_RED << "words[3]: " << e.what() << RST << std::endl;
        }
    }

    {
        Array<char> chars(3);

        chars[0] = 'a';
        chars[1] = 'b';
        chars[2] = 'c';
        try {
            chars[3] = 'd';
        }
        catch (const std::exception& e) {
            std::cerr << PASTEL_RED << "chars[3]: " << e.what() << RST << std::endl;
        }

        try {
            chars[-2] = 'd';
        }
        catch (const std::exception& e) {
            std::cerr << PASTEL_RED << "chars[-2]: " << e.what() << RST << std::endl;
        }
        std::cout << PASTEL_BLUE << chars[0] << " " << chars[1] << " " << chars[2] << RST << std::endl;

        Array<char> letters;

        try {
            std::cout << LAVENDER << letters[0] << RST << std::endl;
        }
        catch (const std::exception& e){
            std::cerr << PASTEL_RED << "letters[0]: " << e.what() << RST << std::endl;
        }
        letters = chars;
        try {
            std::cout << LAVENDER << letters[0] << " " << letters[1] << " " << letters[2] << RST << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << PASTEL_RED << "letters[0]: " << e.what() << RST << "\n" << std::endl;
        }

        letters[0] = 'x';
        chars[0] = 'h';

        std::cout << PASTEL_GREEN << "letters[0]: " << letters[0] << RST << std::endl;
        std::cout << PASTEL_YELLOW << "chars[0]: " << chars[0] << RST << std::endl;
    }
}



/*
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
*/