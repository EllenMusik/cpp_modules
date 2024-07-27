/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:29:36 by esteiner          #+#    #+#             */
/*   Updated: 2024/05/23 16:29:36 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AForm.hpp"
#include "../RobotomyRequestForm.hpp"
#include "../colors.hpp"
#include <stdlib.h>
#include <time.h>

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (!this->getSigned())
        throw AForm::FormNotSignedException();

    std::cout << YELLOW2 << "*Drrrrrr-drrrrrr Drrrr-drrrilling noises*" << RST << std::endl;

    srand(time(NULL));
    int r = rand();
     if (r % 2)
        std::cout << GREEN << _target << " has been robotomized successfully" << RST << std::endl;
    else
        std::cout << RED << _target << " robotomization failed" << RST << std::endl;
}

AForm* RobotomyRequestForm::create(const std::string& target) {
    return new RobotomyRequestForm(target);
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) {
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this == &copy)
        return *this;
    _target = copy._target;
    this->setSigned(copy.getSigned());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}
