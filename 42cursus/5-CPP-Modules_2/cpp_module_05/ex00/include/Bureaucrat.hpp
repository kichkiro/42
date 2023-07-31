/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:07:00 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 23:35:47 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

// Class ---------------------------------------------------------------------->

class Bureaucrat {
    public:
        Bureaucrat(string name, int grade);
        // Bureaucrat(const Bureaucrat &src);
        // Bureaucrat &operator=(const Bureaucrat &rs);
        ~Bureaucrat(void);

        void GradeTooHighException(void);
        void GradeTooLowException(void);

        string getName(void);
        int    getGrade(void);

    private:
        const string _name;
        int          _grade;
};
