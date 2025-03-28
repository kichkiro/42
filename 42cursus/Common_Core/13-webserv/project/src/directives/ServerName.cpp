/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerName.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:48:46 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:48:56 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerName.hpp"

ServerName::ServerName(string context) {
    vector<string> value;

    if (context != "server")
        throw WrongContextExc("ServerName", "server", context);
    value.push_back("");
    this->_type = "server_name";
    this->_is_context = false;
    this->_value_inline = value;
}

ServerName::ServerName(string raw_value, string context) {
    if (context != "server")
        throw WrongContextExc("ServerName", "server", context);
    this->_type = "server_name";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

ServerName::~ServerName() {}
