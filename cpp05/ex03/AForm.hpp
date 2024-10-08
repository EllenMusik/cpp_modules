/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:44:39 by esteiner          #+#    #+#             */
/*   Updated: 2024/05/15 17:44:39 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    AForm(const AForm& src);
    AForm &operator=(const AForm& src);
    virtual ~AForm();

    bool            getSigned() const;
    void            setSigned(bool Signed);
    int             getSignGrade() const;
    int             getExecGrade() const;
    std::string     getName() const;

    void    beSigned(Bureaucrat &bureaucrat);

    virtual void    execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        const char *what() const throw();
    };


private:
    const std::string _name;
    bool              _signed;
    const int         _signGrade;
    const int         _execGrade;
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif