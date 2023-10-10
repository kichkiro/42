/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:55 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/10 20:02:50 by kichkiro         ###   ########.fr       */
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

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rs);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat &executor) const;

    private:
        string _target;
};
