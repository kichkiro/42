/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:25:52 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/30 12:42:12 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// Libraries ------------------------------------------------------------------>

#include "Contact.hpp"
#include "common.hpp"

// Class ---------------------------------------------------------------------->

class PhoneBook
{
    public:	
    
        PhoneBook(void);
        
        void	add_contact(const Contact &contact);
        void	display_contacts(void);

    private:

        Contact	_contacts[8];
        int		_counter;
        int     _total_contacts;
        
        void	_format_table(string str);
};

#endif
