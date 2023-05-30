/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:36:29 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/30 12:04:20 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

int main(void)
{
    PhoneBook   phone_book;
    Contact     contact;
    string      command;

    while (true)
    {
        cout << endl << YELLOW_B << "Enter a command [ADD/SEARCH/EXIT]: ";
        cout << RESET;
        cin >> command;
        if (command == "ADD")
        {
            contact = Contact();
            contact.add_info();
            phone_book.add_contact(contact);
        }
        else if (command == "SEARCH")
            phone_book.display_contacts();
        else if (command == "EXIT")
            break;
    }
    return 0;
}
