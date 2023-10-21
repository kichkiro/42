/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:47 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/10 19:04:46 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <exception>

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
    public:
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

        // Exceptions -------------------------------------------------------->>
        
        class GradeTooHighException : public exception {
            const char *what() const throw() {return "grade too high!";}
        };

        class GradeTooLowException : public exception {
            const char *what() const throw() {return "grade too low!";}
        };

        class FormIsNotSignedException : public exception {
            const char *what() const throw() {return "form is not signed!";}
        };
        
        class FormIsAlreadySignedException : public exception {
            const char *what() const throw() {return "form is already signed!";} 
        };
        
    private:
        const string _name;
        bool         _is_signed;
        const int    _to_sign;
        const int    _to_exec;
};

ostream &operator<<(ostream &out, const AForm &rs);
