/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:36:29 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/30 02:08:49 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

int main(void)
{
    PhoneBook   phone_book;
    Contact     contact;
    string      command;
    int         index;

    while (true)
    {
        cout << YELLOW << "Enter a command (ADD, SEARCH, EXIT): " << RESET;
        cin >> command;
        if (command == "ADD")
        {
            contact = Contact();
            contact.add_info();
            phone_book.add_contact(contact);
            cout << "Contact added successfully." << endl;
        }
        else if (command == "SEARCH")
        {
            // TODO
        }
        else if (command == "EXIT")
            break;
    }
    return 0;
}
