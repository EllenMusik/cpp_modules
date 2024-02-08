/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:13:54 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/31 12:13:54 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PhoneBook.hpp"

int main() {
	PhoneBook MyPhoneBook;
	std::string TempInput;
	int index;

	index = 0;
	while (1)
	{
		std::cout << "Type in ADD, SEARCH or EXIT." << std::endl;
		std::cin >> TempInput;
		if (TempInput == "ADD" || TempInput == "add")
		{
			std::cout << "Adding a new contact... (note: info can never be empty)" << std::endl;
			MyPhoneBook.AddContact(index);
			if (index < 7)
				index++;
			else
				index = 0;
		}
		else if (TempInput == "SEARCH" || TempInput == "search")
		{
			int index;

			std::cout << "\nExisting Contacts: " << std::endl;
			MyPhoneBook.DisplayAllContacts();
			std::cout << "Give an index between 1 and 8 to display the matching contact: ";
			std::cin >> index;
			if (std::cin.fail()) {
      	  		std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
        		std::cout << "Invalid input. You have to enter an integer.\n" << std::endl;
			}
			else if (index >= 1 && index <= 8)
				MyPhoneBook.DisplayContact(index - 1);
			else
				std::cout << "Please only put a number between 1 and 8, nothing else." << std::endl;
		}
		else if (TempInput == "EXIT" || TempInput == "exit")
		{
			std::cout << "Exiting the program." << std::endl;
			return (0);
		}
	}
	return (0);
}
