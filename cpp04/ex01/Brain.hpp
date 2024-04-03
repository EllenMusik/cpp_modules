/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:01:44 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/26 14:01:44 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Brain{
public:
    Brain();
    ~Brain();
    Brain(const Brain& source);
    Brain &operator=(const Brain& source);

    void addIdea(std::string idea);
    void showIdeas(void);

private:
    std::string _ideas[100];
};

#endif
