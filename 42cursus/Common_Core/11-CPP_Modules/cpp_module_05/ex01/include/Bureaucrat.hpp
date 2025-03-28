/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:07:00 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 10:44:58 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <exception>
#include <string>

#include "Form.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::string;
using std::exception;

// Class ---------------------------------------------------------------------->

class Form;

class Bureaucrat {
    private:
        const string _name;
        int          _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &rs);
        ~Bureaucrat(void);

        string getName(void) const;
        int    getGrade(void) const;
        void   incrementGrade(void);
        void   decrementGrade(void);
        void   signForm(Form &form);

        class GradeTooHighException : public exception {
            const char *what(void) const throw();
        };

        class GradeTooLowException : public exception {
            const char *what(void) const throw();
        };
};

ostream &operator<<(ostream &out, const Bureaucrat &rs);
