/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:37:14 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/10 20:22:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <cstdlib>

#include "AForm.hpp"

using std::string;
using std::cout;

// Class ---------------------------------------------------------------------->

class AForm;

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rs);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat &executor) const;

    private:
        string _target;
};
