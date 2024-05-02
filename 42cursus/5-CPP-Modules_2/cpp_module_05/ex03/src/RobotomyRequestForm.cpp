/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:49 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 11:45:35 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
    AForm(), _target("def") {}

RobotomyRequestForm::RobotomyRequestForm(string target) : 
    AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : 
    AForm(src.getName(), 72, 45), _target(src._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &rs) {
    if (this != &rs)
        this->_target = rs._target;
    return *this;    
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned())
        throw FormIsNotSignedException();
    else if (executor.getGrade() > this->getRequiredGradeToExecute())
        throw GradeTooLowException();
    else {
        cout << "(Makes some drilling noises) ---> ";
        srand(time(NULL));
        if (rand() % 2)
            cout << this->_target << " has been robotomized!" << endl;
        else
            cout << "robotomy failed..." << endl;
    }
}
