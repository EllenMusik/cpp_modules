/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:04:40 by esteiner          #+#    #+#             */
/*   Updated: 2024/07/24 14:11:38 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bureaucrat.hpp"
#include "../colors.hpp"



Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    _name = src._name;
    _grade = src._grade;
}

Bureaucrat::Bureaucrat() {
    _name = "default";
    _grade = 150;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this == &src)
        return *this;
    _grade = src._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << PINK << _name << " executed " << form.getName() << RST << std::endl;
    } catch (std::exception &e) {
        std::cout << PASTEL_GREEN << _name << " cannot execute the form because " << e.what() << RST << std::endl;
    }
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        if (_grade > form.getSignGrade())
            throw Bureaucrat::GradeTooLowException();
        form.beSigned(*this);
    }
    catch (std::exception &e) {
        std::cout << PINK << _name << " cannot sign " << form.getName() << " because " << e.what() << RST << std::endl;
        return;
    }
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
    std::cout << PASTEL_BLUE << _name << " grade incremented to " << _grade << RST << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
    std::cout << PASTEL_BLUE << _name << " grade decremented to " << _grade << RST << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}