/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:43:54 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 10:46:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <string>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::string;

// Classes -------------------------------------------------------------------->

class Intern {
    public:
        Intern(void);
        Intern(const Intern &src);
        Intern &operator=(const Intern &rs);
        ~Intern();

        AForm *makeForm(string form, string target);
};
