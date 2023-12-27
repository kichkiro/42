/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:52 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/11 00:15:20 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(string name, int to_sign, int to_exec) :
    _name(name), _is_signed(false), _to_sign(to_sign), _to_exec(to_exec) {
    if (to_sign < 1 || to_exec < 1)
        throw AForm::GradeTooHighException();
    else if (to_sign > 150 || to_exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) :
    _name(src._name), _is_signed(src._is_signed), _to_sign(src._to_sign), 
    _to_exec(src._to_exec) {}

AForm &AForm::operator=(const AForm &rs) {
    if (this != &rs)
        this->_is_signed = rs._is_signed;
    return *this;
}

AForm::~AForm(void) {}

string AForm::getName(void) const {
    return this->_name;
}

bool AForm::getIsSigned(void) const {
    return this->_is_signed;
}

int AForm::getRequiredGradeToSign(void) const {
    return this->_to_sign;
}

int AForm::getRequiredGradeToExecute(void) const {
    return this->_to_exec;
}

void AForm::beSigned(Bureaucrat &b) {
    if (this->_is_signed)
        throw FormIsAlreadySignedException();
    else if (b.getGrade() > this->_to_sign)
        throw GradeTooLowException();
    else
        this->_is_signed = true;
}

ostream &operator<<(ostream &out, const AForm &rs) {
    out << "Form: " << rs.getName() << endl << "Is signed: " <<
        rs.getIsSigned() << endl << "Required grade to sign: " <<
        rs.getRequiredGradeToSign() << endl << "Required grade to execute: " <<
        rs.getRequiredGradeToExecute();
    return (out);
}
