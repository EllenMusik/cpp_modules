/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:01:36 by esteiner          #+#    #+#             */
/*   Updated: 2024/03/26 14:01:36 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created." << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain(const Brain &source) {
    *this = source;
    std::cout << "Brain copy created." << std::endl;
}

Brain &Brain::operator=(const Brain& source) {
    std::cout << "Brain copy assignment operator called." << std::endl;
    if (this == &source)
        return *this;
    for(size_t i = 0; i < 100; i++)
        this->_ideas[i].assign(source._ideas[i]);
    return (*this);
}

void Brain::addIdea(std::string idea) {
    int i = 0;
    while (i < 100 && !this->_ideas[i].empty())
        i++;
    if (i <= 99){
        this->_ideas[i] = idea;
        return;
    }
    else{
        std::cout << "The head is full, brain can't handle" << std::endl;
        return;
    }
}

void Brain::showIdeas() {
    int i = 0;
    while (i < 100 && !this->_ideas[i].empty()){
        std::cout << this->_ideas[i] << std::endl;
        i++;
    }
}