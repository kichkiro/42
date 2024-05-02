/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:55 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 11:45:21 by kichkiro         ###   ########.fr       */
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

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rs);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat &executor) const;

    private:
        string _target;
};
