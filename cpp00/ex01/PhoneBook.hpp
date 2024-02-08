#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
# include <string>
# include <cctype>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <climits>

class PhoneBook {
public:
	Contact Contacts[8];

	PhoneBook();
	~PhoneBook();
	void AddContact(int index);
	void DisplayAllContacts() const;
	void DisplayContact(int i) const;
private:
};

#endif