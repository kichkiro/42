/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:47 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 10:36:01 by kichkiro         ###   ########.fr       */
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

class Form {
    private:
        const string _name;
        bool         _is_signed;
        const int    _to_sign;
        const int    _to_exec;

    public:
        Form(void);
        Form(string name, int grade_to_sign, int grade_to_exex);
        Form(const Form &src);
        Form &operator=(const Form &rs);
        ~Form(void);

        string getName(void) const;
        bool   getIsSigned(void) const;
        int    getRequiredGradeToSign(void) const;
        int    getRequiredGradeToExecute(void) const;
        void   beSigned(Bureaucrat &b);
        
        class GradeTooHighException : public exception {
            const char *what(void) const throw();
        };

        class GradeTooLowException : public exception {
            const char *what(void) const throw();
        };   
};

ostream &operator<<(ostream &out, const Form &rs);
