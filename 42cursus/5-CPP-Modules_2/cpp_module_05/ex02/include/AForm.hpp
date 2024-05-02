/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:47 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 11:13:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <exception>
#include <string>

#include "Bureaucrat.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::string;
using std::exception;

// Class ---------------------------------------------------------------------->

class Bureaucrat;

class AForm {
    private:
        const string _name;
        bool         _is_signed;
        const int    _to_sign;
        const int    _to_exec;

    public:
        AForm(void);
        AForm(string name, int grade_to_sign, int grade_to_exex);
        AForm(const AForm &src);
        AForm &operator=(const AForm &rs);
        virtual ~AForm(void);

        string       getName(void) const;
        bool         getIsSigned(void) const;
        int          getRequiredGradeToSign(void) const;
        int          getRequiredGradeToExecute(void) const;
        void         beSigned(Bureaucrat &b);
        virtual void execute(const Bureaucrat &executor) const = 0;

        // Exceptions ------------------------------------------------------->>>
        
        class GradeTooHighException : public exception {
            const char *what() const throw();
        };

        class GradeTooLowException : public exception {
            const char *what() const throw();
        };

        class FormIsNotSignedException : public exception {
            const char *what() const throw();
        };
        
        class FormIsAlreadySignedException : public exception {
            const char *what() const throw();
        };
};

ostream &operator<<(ostream &out, const AForm &rs);
