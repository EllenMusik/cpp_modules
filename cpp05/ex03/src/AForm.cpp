/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:44:54 by esteiner          #+#    #+#             */
/*   Updated: 2024/05/15 17:44:54 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AForm.hpp"

AForm::AForm() {
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

std::string AForm::getName() const {
    return _name;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade){
        std::cout << bureaucrat.getName() << " couldn’t sign " << this->_name << " because ";
        throw AForm::GradeTooLowException();
    }
    _signed = true;
    std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form is not signed!";
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs) {
    o << rhs.getName() << ", sign grade " << rhs.getSignGrade() << " and execution grade " << rhs.getExecGrade() << ".";
    return o;
}