#include <iostream>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:13:54 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/31 12:13:54 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook() {
	std::cout << "Phonebook is created." << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "Phonebook is destroyed." << std::endl;
}

static std::string getInput(std::string Question) {
	std::string Input;

	while (Input.empty())
	{
		std::cout << Question << std::endl;
		std::cin >> Input;
	}
	return (Input);
}

void PhoneBook::AddContact(int index) {
	std::string InputTemp;

	InputTemp = getInput("type in first name: ");
	this->Contacts[index].setFirstName(InputTemp);
	InputTemp = getInput("type in last name: ");
	this->Contacts[index].setLastName(InputTemp);
	InputTemp = getInput("type in nickname: ");
	this->Contacts[index].setNickname(InputTemp);
	InputTemp = getInput("type in phone number: ");
	this->Contacts[index].setPhoneNumber(InputTemp);
	InputTemp = getInput("type in your darkest secret: ");
	this->Contacts[index].setSecret(InputTemp);
	std::cout << "Contact creation completed" << std::endl;
}

static void printStringShort(std::string temp) {
	if (temp.length() <= 10) {
		for(unsigned long i = 0; i < 10 - temp.length(); i++)
			std::cout << " ";
		std::cout << temp;
	}
	else
		std::cout << temp.substr(0, 9) << ".";
	std::cout << " | ";
}

void PhoneBook::DisplayAllContacts() const {
	int 		i;
	std::string	temp;

	i = 0;
	temp = this->Contacts[i].getFirstName();
	while (i < 8 && !temp.empty()){
		std::cout << "         " << i + 1 << " | ";
		printStringShort(this->Contacts[i].getFirstName());
		printStringShort(this->Contacts[i].getLastName());
		printStringShort(this->Contacts[i].getNickname());
		std::cout << std::endl;
		i++;
		if (i < 8)
			temp = this->Contacts[i].getFirstName();
	}
	std::cout << "\n";
}

void PhoneBook::DisplayContact(int i) const {
	std::string temp;

	temp = this->Contacts[i].getFirstName();
	if (temp.empty()) {
		std::cout << "This contact does not exist yet." << std::endl;
		return;
	}
	std::cout << "\n";
	std::cout << this->Contacts[i].getFirstName() << std::endl;
	std::cout << this->Contacts[i].getLastName() << std::endl;
	std::cout << this->Contacts[i].getNickname() << std::endl;
	std::cout << this->Contacts[i].getPhoneNumber() << std::endl;
	std::cout << this->Contacts[i].getSecret() << std::endl;
	std::cout << "\n";
}
