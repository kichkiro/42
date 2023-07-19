/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:25:52 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 23:00:57 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include "Contact.hpp"

#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;

// Macros --------------------------------------------------------------------->

#define RESET "\033[0m"
#define RED_B "\033[1;31m"
#define BLUE_B "\033[1;34m"
#define YELLOW_B "\033[1;33m"
#define WHITE_B "\033[1;37m"

// Class ---------------------------------------------------------------------->

class PhoneBook {
    public:
        PhoneBook(void);

        void add_contact(const Contact &contact);
        void display_contacts(void);

    private:
        Contact _contacts[8];
        int _counter;
        int _total_contacts;

        void _format_table(string str);
};
