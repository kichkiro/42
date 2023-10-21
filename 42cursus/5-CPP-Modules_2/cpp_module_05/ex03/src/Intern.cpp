/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:43:24 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/11 01:14:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &src) {}

Intern &Intern::operator=(const Intern &rs) {return *this;}

Intern::~Intern() {}

AForm *makeForm(string form, string target) {
    AForm *forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };



}
