/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:18 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 11:19:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm(), _target("def") {}

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
