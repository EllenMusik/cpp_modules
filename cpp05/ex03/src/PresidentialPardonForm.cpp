/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:29:26 by esteiner          #+#    #+#             */
/*   Updated: 2024/05/23 16:29:26 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AForm.hpp"
#include "../PresidentialPardonForm.hpp"
#include "../colors.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > _execGrade)
        throw AForm::GradeTooLowException();
    if (!_signed)
        throw AForm::FormNotSignedException();
    std::cout << TURQUOISE << _target << " has been pardoned by Zafod Beeblebrox" << RST << std::endl;
}

AForm* PresidentialPardonForm::create(const std::string& target) {
    return new PresidentialPardonForm(target);
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) {
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    if (this == &copy)
        return *this;
    _target = copy._target;
    _signed = copy._signed;
    _execGrade = copy._execGrade;
    _signGrade = copy._signGrade;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}
