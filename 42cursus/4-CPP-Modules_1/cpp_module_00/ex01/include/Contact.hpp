/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:25:55 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 13:03:55 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

// Class ---------------------------------------------------------------------->

class Contact
{
    public:

        Contact(void);

        string	first_name;
        string	last_name;
        string	nickname;
        string	phone_number;
        string	darkest_secret;

        void	add_info(void);
        void	get_info(void);
};
