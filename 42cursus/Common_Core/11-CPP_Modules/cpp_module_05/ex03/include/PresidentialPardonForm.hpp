/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:37:14 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 11:44:11 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <cstdlib>
#include <string>

#include "AForm.hpp"

using std::string;
using std::cout;

// Class ---------------------------------------------------------------------->

class AForm;

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rs);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat &executor) const;

    private:
        string _target;
};
