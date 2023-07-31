/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:08:37 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 23:38:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        Bureaucrat::GradeTooLowException();
}

// Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    
// }

// Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rs) {
    
// }

Bureaucrat::~Bureaucrat(void) {}

void Bureaucrat::GradeTooHighException(void) {
    throw runtime_error("Error: grade too high!");
}

void Bureaucrat::GradeTooLowException(void) {
    throw runtime_error("Error: grade too low!");
}

string Bureaucrat::getName(void) {
    return this->_name;
}

int Bureaucrat::getGrade(void) {
    return this->_grade;
}
