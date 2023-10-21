/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:37:07 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/10 20:25:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(string target) : 
    AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : 
    AForm(src.getName(), 25, 5), _target(src._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &rs) {
    if (this != &rs)
        this->_target = rs._target;
    return *this;    
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned())
        throw FormIsNotSignedException();
    else if (executor.getGrade() > this->getRequiredGradeToExecute())
        throw GradeTooLowException();
    else {
        cout << this->_target << " has been pardoned by Zaphod Beeblebrox" 
            << endl;
    }
}
