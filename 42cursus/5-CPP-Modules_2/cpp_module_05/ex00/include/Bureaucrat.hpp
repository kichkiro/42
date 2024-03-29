/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:07:00 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/10 19:07:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <exception>

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::string;
using std::exception;

// Class ---------------------------------------------------------------------->

class Bureaucrat {
    public:
        Bureaucrat(string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &rs);
        ~Bureaucrat(void);

        string getName(void) const;
        int    getGrade(void) const;
        void   incrementGrade(void);
        void   decrementGrade(void);

        class GradeTooHighException : public exception {
            const char *what(void) const throw() {return "grade too high!";}
        };

        class GradeTooLowException : public exception {
            const char *what(void) const throw() {return "grade too low!";}
        };

    private:
        const string _name;
        int          _grade;
};

ostream &operator<<(ostream &out, const Bureaucrat &rs);
