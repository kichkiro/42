/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:43:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/27 11:18:23 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

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
