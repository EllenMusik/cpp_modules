/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:13:54 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/31 12:13:54 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Contact.hpp"

Contact::Contact() {
	//std::cout << "contact constructor" << std::endl;
}

Contact::~Contact() {
	//std::cout << "contacts deconstructor" << std::endl;
}

std::string Contact::getFirstName() const {
	return (this->_FirstName);
}

std::string Contact::getLastName() const {
	return (this->_LastName);
}

std::string Contact::getNickname() const {
	return (this->_Nickname);
}

std::string Contact::getPhoneNumber() const {
	return (this->_PhoneNumber);
}

std::string Contact::getSecret() const {
	return (this->_Secret);
}

void Contact::setFirstName(std::string first_name) {
	this->_FirstName = first_name;
}

void Contact::setLastName(std::string last_name) {
	this->_LastName = last_name;
}

void Contact::setNickname(std::string nickname) {
	this->_Nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number) {
	this->_PhoneNumber = phone_number;
}

void Contact::setSecret(std::string secret){
	this->_Secret = secret;
}
