/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:18 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/11 01:07:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) :
    AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
    AForm(src.getName(), 145, 137), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &rs) {
    if (this != &rs)
        this->_target = rs._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned())
        throw FormIsNotSignedException();
    else if (executor.getGrade() > this->getRequiredGradeToExecute())
        throw GradeTooLowException();
    else {
        ofstream file((this->_target + "_shruberry").c_str());       
        if (!file.is_open())
            throw runtime_error("error while opening file.");
        file << "                          # #### ####                " << endl;
        file << "                      ### //#|### |/####             " << endl;
        file << "                    ##//#/ /||/##/_/##/_#            " << endl;
        file << "                   ###  //###|/ // # ###             " << endl;
        file << "                ##_/_#/_/## | #/###_/_####           " << endl;
        file << "                ## #### # / #| /  #### ##/##         " << endl;
        file << "                 __#_--###`  |{,###---###-~          " << endl;
        file << "                           / }{                      " << endl;
        file << "                            }}{                      " << endl;
        file << "                           }}{                       " << endl;
        file << "                           {{}                       " << endl;
        file << "                      , -=-~{ .-^- _;                " << endl;
    }
}
