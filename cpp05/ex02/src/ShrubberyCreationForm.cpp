/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:29:44 by esteiner          #+#    #+#             */
/*   Updated: 2024/07/26 19:24:10 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
    _target = target;
    this->setSigned(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this == &copy)
        return *this;
    _target = copy._target;
    this->setSigned(copy.getSigned());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream file;
    std::string tmp = _target + "_shrubbery";
    file.open(tmp.c_str());
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