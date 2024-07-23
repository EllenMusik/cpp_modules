/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:52:20 by esteiner          #+#    #+#             */
/*   Updated: 2024/05/14 15:52:20 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdio.h>

class Bureaucrat
{
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &src);
    
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    std::string getName() const;
    int getGrade() const;

    void signForm(Form &form);
    void incrementGrade();
    void decrementGrade();
private:
    std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif