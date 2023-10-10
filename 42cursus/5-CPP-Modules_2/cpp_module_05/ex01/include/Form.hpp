/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:47 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/08 12:20:51 by kichkiro         ###   ########.fr       */
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

class Form {
    public:
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
            public:
                GradeTooHighException(void) : _e("grade too high!") {}
                virtual ~GradeTooHighException() throw() {}
                const char *what(void) const throw() {return this->_e.c_str();}
            private:
                string _e;
        };

        class GradeTooLowException : public exception {
            public:
                GradeTooLowException(void) : _e("grade too low!") {}
                virtual ~GradeTooLowException() throw() {}
                const char *what(void) const throw() {return this->_e.c_str();}
            private:
                string _e;
        };
        
    private:
        const string _name;
        bool         _is_signed;
        const int    _to_sign;
        const int    _to_exec;
};

ostream &operator<<(ostream &out, const Form &rs);
