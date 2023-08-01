/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:07:00 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/01 11:23:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <exception>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;

// Class ---------------------------------------------------------------------->

class Bureaucrat {
    public:
        class GradeTooHighException : public exception {
            public:
                GradeTooHighException(void) : _err("grade too high!") {}
                virtual ~GradeTooHighException() throw() {}
                const char *what(void) const throw() {
                    return this->_err.c_str();
                }
            private:
                string _err;
        };

        class GradeTooLowException : public exception {
            public:
                GradeTooLowException(void) : _err("grade too low!") {}
                virtual ~GradeTooLowException() throw() {}
                const char *what(void) const throw() {
                    return this->_err.c_str();
                }
            private:
                string _err;
        };

        Bureaucrat(string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &rs);
        ~Bureaucrat(void);

        string getName(void);
        int    getGrade(void);
        void   incrementGrade(void);
        void   decrementGrade(void);
        
    private:
        const string _name;
        int          _grade;
};
