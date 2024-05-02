/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:08:37 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 11:14:09 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("def"), _grade(150) {}

Bureaucrat::Bureaucrat(string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) :
    _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rs) {
    if (this != &rs)
        this->_grade = rs._grade;
    return *this;
}

Bureaucrat::~Bureaucrat(void) {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat: grade too low!";
}

string Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void Bureaucrat::incrementGrade(void) {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade += 1;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        cout << this->_name << " signed " << form.getName() << endl;
    }
    catch (const exception &e) {
        cerr << this->_name << " couldn't sign " << form.getName() <<
            " because " << e.what() << endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) {
    try {
        form.execute(*this);
        cout << this->_name << " executed " << form.getName() << endl;
    }
    catch (const exception &e) {
        cerr << this->_name << " couldn't execute " << form.getName() <<
            " because " << e.what() << endl;
    }
}

ostream &operator<<(ostream &out, const Bureaucrat &rs) {
    out << rs.getName() << ", bureaucrat grade " << rs.getGrade();
    return (out);
}
