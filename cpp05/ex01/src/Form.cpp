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

#include "../Form.hpp"
#include "../Bureaucrat.hpp"

Form::Form() :
 _name("default"), _signed(false), _signGrade(1), _execGrade(1) {
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {
}

Form &Form::operator=(const Form &src) {
    if (this == &src)
        return *this;
    _signed = src._signed;
    return *this;
}

Form::~Form() {
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}

std::string Form::getName() const {
    return _name;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
    std::cout << _name << " was signed by " << bureaucrat.getName() << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, const Form &rhs) {
    o << rhs.getName() << ", sign grade " << rhs.getSignGrade() << " and execution grade " << rhs.getExecGrade() << ".";
    return o;
}