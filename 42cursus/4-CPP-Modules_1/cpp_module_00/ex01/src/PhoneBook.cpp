/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:23:53 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/30 02:09:11 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

PhoneBook::PhoneBook(void)
{
	contact_count = 0;
}

void PhoneBook::add_contact(const Contact& contact)
{
	if (contact_count == 8)
		contact_count = 0;
	contacts[contact_count] = contact;
	contact_count++;
}

void PhoneBook::display_contacts(void)
{
    // TODO
}
