/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:56:07 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/13 13:56:07 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Harl {
public:
    void complain(std::string level);
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};
#endif