/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:24:16 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/30 12:00:53 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

Contact::Contact(void)
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

void Contact::add_info(void)
{
    cout << endl << "Enter contact information:" << endl;
    cout << "First Name: ";
    cin >> this->first_name;
    cout << "Last Name: ";
    cin >> this->last_name;
    cout << "Nickname: ";
    cin >> this->nickname;
    cout << "Phone Number: ";
    cin >> this->phone_number;
    cout << "Darkest Secret: ";
    cin >> this->darkest_secret;
}

void Contact::get_info(void)
{
    cout << endl << "Contact information:" << endl;
    cout << "First Name:     " << this->first_name << endl;
    cout << "Last Name:      " << this->last_name << endl;
    cout << "Nickname:       " << this->nickname << endl;
    cout << "Phone Number:   " << this->phone_number << endl;
    cout << "Darkest Secret: " << this->darkest_secret << endl;
}
