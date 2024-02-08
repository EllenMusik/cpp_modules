/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:13:54 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/31 12:13:54 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <string>
# include <cctype>
# include <iostream>

class ft_std {
public:
	void static cout(std::string str) {
		for (int c = 0; str[c]; c++) {
			if (islower(str[c]))
				str[c] = toupper(str[c]);
		}
		std::cout << str;
	}
};

int main(int argc, char **argv) {
	int i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (i = 1; argc > i; i++)
		ft_std::cout(argv[i]);
	std::cout << std::endl;
	return (0);
}
