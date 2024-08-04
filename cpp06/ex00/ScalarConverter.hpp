/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:44:39 by esteiner          #+#    #+#             */
/*   Updated: 2024/07/27 15:56:22 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include "stdlib.h"
#include "colors.hpp"
#include "limits.h"
#include <cerrno>


class ScalarConverter {
    public:
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);

        static void convert(const std::string &input);

    private:
    bool check() const;
        ScalarConverter();
};

#endif