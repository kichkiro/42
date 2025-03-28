/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Autoindex.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:50:21 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:50:34 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Autoindex.hpp"

Autoindex::Autoindex(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("Autoindex", "http|server|location", context);
    value.push_back("off");
    this->_type = "autoindex";
    this->_is_context = false;
    this->_value_inline = value;
}

Autoindex::Autoindex(string raw_value, string context) {
    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("Autoindex", "http|server|location", context);
    this->_type = "autoindex";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Autoindex::~Autoindex() {}
