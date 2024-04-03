/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:38:02 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/03 10:30:25 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource& source);
    MateriaSource &operator=(const MateriaSource& source);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
private:
    AMateria *_templates[4];
};

#endif