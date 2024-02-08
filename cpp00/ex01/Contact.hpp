#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>


class Contact {
public:
	Contact();
	~Contact();

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getSecret() const;

	void setFirstName(std::string first_name);
	void setLastName(std::string last_name);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phone_number);
	void setSecret(std::string secret);
	
private:
	std::string _FirstName;
	std::string _LastName;
	std::string _Nickname;
	std::string _PhoneNumber;
	std::string _Secret;
};

#endif
