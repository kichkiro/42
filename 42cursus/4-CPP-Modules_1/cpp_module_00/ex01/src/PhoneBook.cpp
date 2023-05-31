/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:23:53 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/30 12:40:34 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

PhoneBook::PhoneBook(void)
{
    this->_counter = 0;
    this->_total_contacts = 0;
}

void PhoneBook::add_contact(const Contact &contact)
{
    if (this->_counter == 8)
        this->_counter = 0;
    if (this->_total_contacts < 8)
        this->_total_contacts++;
    this->_contacts[this->_counter] = contact;
    this->_counter++;
    cout << endl << BLUE_B << "Contact added successfully." << RESET << endl;
}

void PhoneBook::display_contacts(void)
{
    Contact contact;
    int index;

    cout << WHITE_B << endl << "+------------------------------------------+";
    cout  << endl << "|    Index|First Name| Last Name|  Nickname|" << endl;
    for (int i = 0; i < this->_total_contacts; ++i)
    {
        cout << "+---------+----------+----------+----------+" << endl;
        cout << "|" << setw(9) << i << "|";
        this->_format_table(this->_contacts[i].first_name);
        this->_format_table(this->_contacts[i].last_name);
        this->_format_table(this->_contacts[i].nickname);
        cout << endl;
    }
    cout << "+------------------------------------------+" << endl << endl;
    cout << YELLOW_B << "Enter the index of the contact to display: " << RESET;
    cin >> index;
    if (index >= 0 && index < this->_total_contacts)
    {
        contact = this->_contacts[index];
        contact.get_info();
    }
    else
        cout << endl << RED_B << "Invalid index." << RESET << endl;
}

void PhoneBook::_format_table(string str)
{
    if (str.length() > 10)
        cout << setw(9) << str.substr(0, 9) << ".|";
    else
        cout << setw(10) << str.substr(0, 10) << "|";
}
