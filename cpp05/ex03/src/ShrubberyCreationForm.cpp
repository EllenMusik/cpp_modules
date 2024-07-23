/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:29:44 by esteiner          #+#    #+#             */
/*   Updated: 2024/05/23 16:29:44 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
    _target = target;
    _signed = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) {
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    _target = copy._target;
    _signed = copy._signed;
    _execGrade = copy._execGrade;
    _signGrade = copy._signGrade;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

AForm* ShrubberyCreationForm::create(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!_signed)
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > _execGrade)
        throw AForm::GradeTooLowException();

    std::ofstream file;
    file.open(_target + "_shrubbery");
    file <<    "░░                                                                           ▓▓▒▒░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                                                                          ▒▒▒▒░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                                                                  ▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                                                                  ▓▓▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                                                                ▒▒▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                                                              ░░▒▒▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                                                            ░░▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                                      ░░░░░░░░░░░░░░░░      ▒▒▒▒░░░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░░░░░░" << std::endl;
    file <<    "░░                                    ░░░░░░░░░░░░░░░░░░░░   ░░░░░▒▒▒▒▒▒░░░░░░░░░░░░░░▒▒▒▒░░░░░░░░░░░░░░░░▒▒▒▒" << std::endl;
    file <<    "░░                                ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒░░░░░░░░░░░░░░▒▒▒▒▓▓▒▒░░░░░░▒▒▒▒░░░░▒▒▓▓" << std::endl;
    file <<    "░░                              ░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░▒▒▓▓▒▒▒▒░░▒▒▒▒░░▒▒▒▒▓▓▓▓" << std::endl;
    file <<    "░░                        ░░░░▒▒░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓" << std::endl;
    file <<    "░░                        ░░░░▓▓▒▒░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓░░▒▒▒▒░░▒▒▒▒▒▒▒▒" << std::endl;
    file <<    "░░                    ▓▓▓▓░░░░▓▓▒▒░░░░░░░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▓▓▒▒▓▓▒▒▒▒▓▓" << std::endl;
    file <<    "░░                    ▓▓▓▓▒▒▒▒░░▒▒▒▒░░░░░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▓▓▓▓▓▓▓▓" << std::endl;
    file <<    "░░                    ▓▓▓▓░░░░▒▒▓▓░░▒▒▒▒░░░░░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░░░▓▓▓▓▓▓  ░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                    ▓▓▓▓░░░░▓▓▓▓░░▓▓▒▒░░░░░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒░░░░▒▒▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                    ▓▓▒▒▒▒▓▓▓▓▒▒▓▓▒▒░░▒▒░░░░░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░▒▒▒▒░░▒▒▒▒░░░░▒▒▒▒▒▒▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░                    ▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒▒▒░░▒▒░░░░░░▒▒░░░░▒▒▒▒▒▒░░▒▒▒▒░░▒▒▒▒▒▒▒▒▓▓▒▒░░▒▒░░░░▒▒▓▓▒▒░░░░░░░░░░▓▓" << std::endl;
    file <<    "░░                        ░░░░▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒▓▓▒▒▒▒▒▒░░░░▒▒▒▒░░▒▒▒▒░░▒▒▒▒░░▒▒▒▒▓▓▒▒▒▒  ▓▓▒▒▒▒▒▒▒▒░░▓▓▓▓▒▒░░░░░░░░░░▒▒░░" << std::endl;
    file <<    "░░                        ░░░░░░░░░░░░░░▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▓▓▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▓▓▒▒▒▒  ▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░░░▒▒▒▒▒▒" << std::endl;
    file <<    "░░          ░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▒▒▒▒▓▓▒▒▓▓░░" << std::endl;
    file <<    "░░          ░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░░░▒▒▒▒░░▒▒▒▒▓▓░░▒▒░░░░▒▒▓▓▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒▒▓▓░░    ░░░░▒▒▒▒▒▒▒▒▓▓▓▓░░░░▓▓▒▒▒▒▓▓░░" << std::endl;
    file <<    "░░          ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░  ░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▒▒░░▒▒" << std::endl;
    file <<    "░░        ░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒░░░░▒▒▒▒░░▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒      ░░░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▒▒" << std::endl;
    file <<    "░░        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓              ▒▒░░▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒░░▒▒" << std::endl;
    file <<    "░░  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒          ░░░░░░░░▒▒▒▒▒▒▓▓░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░░░░░░░░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▓▓▓▓    ▒▒▒▒░░░░        ░░░░░░░░▓▓▓▓▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▓▓▓▓    ▒▒▒▒▒▒▒▒░░    ░░░░░░▒▒▒▒▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▓▓▓▓      ▓▓▓▓▒▒░░░░  ░░░░░░▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▓▓▓▓▓▓░░  ▒▒▓▓▒▒░░░░░░░░░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░░░░░▒▒▒▒░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒  ▒▒▓▓▒▒░░░░░░░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░    ▒▒▒▒▒▒▒▒░░▒▒▒▒░░▒▒▒▒▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    file <<    "░░▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓░░      ▓▓▓▓▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒" << std::endl;
    file <<    "░░▓▓▒▒▒▒▒▒░░▒▒▒▒░░▒▒▓▓▒▒░░░░░░░░▒▒▒▒▓▓░░▒▒░░░░▒▒▒▒░░▒▒▓▓▓▓▓▓░░░░░░  ▒▒▓▓▒▒░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░▒▒▒▒" << std::endl;
    file <<    "░░  ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒░░░░▒▒▒▒░░▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓░░▒▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░▒▒▒▒▒▒" << std::endl;
    file <<    "░░    ▒▒▒▒▒▒▒▒▒▒▒▒▓▓░░▒▒▒▒░░░░▒▒▒▒░░▓▓▓▓▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▓▓▓▓▒▒░░░░░░░░░░░░░░░░▒▒▒▒▒▒▓▓▒▒▒▒░░▒▒▒▒░░▒▒▒▒░░▒▒▒▒▓▓▒▒░░░░░░░░░░▒▒▓▓▒▒▒▒" << std::endl;
    file <<    "░░        ▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▓▓░░▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒      ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░░░▒▒▒▒▒▒▒▒░░▓▓▒▒▒▒░░▒▒▒▒░░▒▒▒▒░░▓▓▓▓▒▒░░░░░░▒▒▓▓▓▓░░" << std::endl;
    file <<    "░░        ░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒░░▒▒      ▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒░░░░░░▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░" << std::endl;
    file <<    "░░                ▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓░░                          ▓▓▓▓▒▒░░░░░░░░▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓" << std::endl;
    file <<    "░░                ░░░░░░░░░░░░░░░░░░░░░░                            ░░░░▓▓▒▒▒▒▒▒░░░░░░▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▒▒░░░░" << std::endl;
    file <<    "░░                                                                      ░░▒▒░░▒▒▒▒░░░░▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒  ▓▓" << std::endl;
    file <<    "░░                                                                            ░░▓▓░░░░░░▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒" << std::endl;
    file <<    "░░                                                                              ░░▒▒▒▒░░░░░░▒▒▓▓▓▓░░▒▒▒▒▒▒▒▒▒▒▓▓" << std::endl;
    file <<    "░░                                                                              ░░▓▓▒▒░░░░░░░░▓▓▓▓  ░░░░░░░░░░░░" << std::endl;
    file <<    "░░                                                                              ▒▒▒▒▒▒░░░░░░░░▓▓▓▓" << std::endl;
    file <<    "░░                                                                            ▒▒▒▒▒▒▒▒░░░░░░░░▓▓▓▓" << std::endl;
    file <<    "░░                                                                      ▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒░░░░▓▓▓▓" << std::endl;
    file <<    "░░                                                                    ▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▒▓▓░░" << std::endl;
    file <<    "░░                                                                  ▒▒▓▓▒▒░░░░░░░░░░░░░░▒▒▒▒▓▓" << std::endl;
    file <<    "░░                                                      ▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒░░░░░░░░░░░░░░▒▒▒▒" << std::endl;
    file <<    "░░                                                  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓" << std::endl;
    file <<    "░░                                                  ▒▒▓▓▒▒░░░░░░░░░░░░░░░░░░▒▒▓▓▓▓▓▓▓▓" << std::endl;
    file <<    "░░                                                  ▒▒▓▓▒▒░░░░░░░░░░░░▒▒▒▒▒▒▓▓▓▓▓▓▓▓" << std::endl;
    file <<    "░░                                                  ▒▒▒▒▒▒░░░░░░░░░░▒▒▓▓▓▓▓▓▒▒" << std::endl;
    file <<    "░░                                            ▒▒▒▒▒▒▒▒░░▒▒░░░░▒▒▒▒▒▒▓▓░░" << std::endl;
    file <<    "░░                                          ░░▒▒▒▒▒▒▒▒░░░░░░░░▒▒▓▓▓▓▓▓" << std::endl;
    file <<    "░░                                        ░░▒▒░░▒▒░░░░░░░░░░░░▒▒▓▓░░" << std::endl;
    file <<    "░░                              ▒▒▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░▒▒░░░░░░▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓░░" << std::endl;
    file <<    "░░                              ▒▒▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░▒▒▓▓▒▒░░░░▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓" << std::endl;
    file <<    "░░            ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << std::endl;
    file <<    "░░          ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒░░▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒░░▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░" << std::endl;
    file <<    "░░          ▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██" << std::endl;
    file <<    "░░        ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░" << std::endl;
    file <<    "░░        ▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓████▓▓▓▓██▓▓▓▓▓▓▓▓░░" << std::endl;
    file <<    "░░        ▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓██▓▓░░" << std::endl;
    file <<    "░░        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░" << std::endl;
    file <<    "░░        ▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓██▓▓" << std::endl;
    file <<    "░░        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓██" << std::endl;
    file <<    "░░        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░" << std::endl;
    file <<    "░░      ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓" << std::endl;
    file <<    "░░        ▓▓████▓▓▓▓▓▓████▓▓▓▓▓▓██▓▓▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓░░" << std::endl;
    file <<    "░░        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << std::endl;
    file <<    "░░        ▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓░░" << std::endl;
    file <<    "░░        ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██" << std::endl;
    file <<    "░░        ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██" << std::endl;
    file <<    "░░        ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓██" << std::endl;
    file <<    "░░            ▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓██▓▓▓▓██▓▓░░░░" << std::endl;
    file <<    "░░            ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓██▓▓" << std::endl;
    file <<    "░░            ▒▒▓▓▓▓▓▓████▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓██▓▓" << std::endl;
    file <<    "░░              ▒▒██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▒▒▒▒" << std::endl;
    file <<    "░░                ░░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▒▒▒▒▒▒" << std::endl;
    file <<    "░░                        ▓▓▓▓██▓▓▓▓▓▓▓▓░░                                                      ██▓▓▓▓▓▓▓▓▓▓██" << std::endl;
    file <<    "░░                        ░░▓▓▓▓▓▓▓▓██                                                          ░░▒▒▓▓▓▓▓▓  ░░" << std::endl;
    file <<    "░░                          ▓▓▓▓██▓▓██                                                              ▓▓▓▓▓▓" << std::endl;
    file <<    "░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;

    file << std::endl;
    file.close();
}