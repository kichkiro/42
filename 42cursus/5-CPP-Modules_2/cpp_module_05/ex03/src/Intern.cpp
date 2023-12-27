/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:43:24 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/27 11:18:49 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &src) {*this = src;}

Intern &Intern::operator=(const Intern &rs) {(void)rs; return *this;}

Intern::~Intern(void) {}

AForm *Intern::makeForm(string form, string target) {
    AForm *forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *selectedForm = NULL;
    for (int i = 0; i < 3; ++i) {
        if (names[i] == form) {
            cout << "Intern creates " << form << endl;
            selectedForm = forms[i];
        }
        else
            delete forms[i];
    }
    if (!selectedForm)
        cerr << "Error: Form " << form << " not found." << endl;
    return selectedForm;
}
