/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:48:29 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:48:36 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Root.hpp"

Root::Root(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("Root", "http|server|location", context);
    value.push_back("html");
    this->_type = "root";
    this->_is_context = false;
    this->_value_inline = value;
}

Root::Root(string raw_value, string context) {
    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("Root", "http|server|location", context);
    this->_type = "root";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Root::~Root() {}
