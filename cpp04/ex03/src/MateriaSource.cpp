/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:32:49 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/03 10:32:49 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MateriaSource.hpp"
#include "../IMateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
    for (int i = 0; i < 4; i++) {
        this->_templates[i] = NULL;
    }
    std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4 ; i++)
    {
        if (this ->_templates[i])
            delete this->_templates[i];
    }
    std::cout << "MateriaSource destructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& source) : IMateriaSource() {
    *this = source;
    std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& source){
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i]) {
            delete this->_templates[i];
        }
        if (source._templates[i]) {
            this->_templates[i] = source._templates[i];
        }
        else
            this->_templates[i] = NULL;
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!this->_templates[i]) {
            this->_templates[i] = m;
            break;
        }
        else if (i == 3)
            std::cout << "templates full!" << std::endl;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] && this->_templates[i]->getType() == type)
            return (this->_templates[i]->clone());
    }
    std::cout << "type not found!" << std::endl;
    return (0);
}