/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:31 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 11:46:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <fstream>
#include <iostream>
#include <exception>
#include <string>

#include "AForm.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::runtime_error;

// Class ---------------------------------------------------------------------->

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rs);
        ~ShrubberyCreationForm(void);

        void execute(const Bureaucrat &executor) const;
        
    private:
        string _target;
};
