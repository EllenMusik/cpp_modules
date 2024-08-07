/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:44:39 by esteiner          #+#    #+#             */
/*   Updated: 2024/05/15 17:44:39 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form();
    Form(std::string name, int signGrade, int execGrade);
    Form(const Form& src);
    Form &operator=(const Form& src);
    ~Form();

    bool            getSigned() const;
    int             getSignGrade() const;
    int             getExecGrade() const;
    std::string     getName() const;

    void            beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    const std::string   _name;
    bool                _signed;
    const int           _signGrade;
    const int           _execGrade;
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif