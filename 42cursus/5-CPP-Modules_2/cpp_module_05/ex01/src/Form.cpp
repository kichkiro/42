/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:52 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 10:31:19 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : 
    _name("def"), 
    _is_signed(false), 
    _to_sign(150), 
    _to_exec(150) {}

Form::Form(string name, int to_sign, int to_exec) :
    _name(name), _is_signed(false), _to_sign(to_sign), _to_exec(to_exec) {
    if (to_sign < 1 || to_exec < 1)
        throw Form::GradeTooHighException();
    else if (to_sign > 150 || to_exec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src) :
    _name(src._name), _is_signed(src._is_signed), _to_sign(src._to_sign),
    _to_exec(src._to_exec) {}

Form &Form::operator=(const Form &rs) {
    if (this != &rs)
        this->_is_signed = rs._is_signed;
    return *this;
}

Form::~Form(void) {}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form: grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form: grade too low!";
}

string Form::getName(void) const {
    return this->_name;
}

bool Form::getIsSigned(void) const {
    return this->_is_signed;
}

int Form::getRequiredGradeToSign(void) const {
    return this->_to_sign;
}

int Form::getRequiredGradeToExecute(void) const {
    return this->_to_exec;
}

void Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->_to_sign)
        this->_is_signed = true;
    else
        throw Form::GradeTooLowException();
}

ostream &operator<<(ostream &out, const Form &rs) {
    out << "Form: " << rs.getName() << endl << "Is signed: " <<
        rs.getIsSigned() << endl << "Required grade to sign: " <<
        rs.getRequiredGradeToSign() << endl << "Required grade to execute: " <<
        rs.getRequiredGradeToExecute();
    return (out);
}
