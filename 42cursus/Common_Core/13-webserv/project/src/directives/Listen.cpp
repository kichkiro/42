/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:48:03 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 16:08:00 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Listen.hpp"

Listen::Listen(string context) {
    vector<string> value;

    if (context != "server")
        throw WrongContextExc("Listen", "server", context);
    value.push_back("*:80");
    this->_type = "listen";
    this->_is_context = false;
    this->_value_inline = value;
}

Listen::Listen(string raw_value, string context) {
    if (context != "server")
        throw WrongContextExc("Listen", "server", context);
    this->_type = "listen";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Listen::~Listen() {}

// vector<int> Listen::get_ports(void) const {
    
// }
