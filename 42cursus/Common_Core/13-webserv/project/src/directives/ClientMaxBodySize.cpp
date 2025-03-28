/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientMaxBodySize.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:49:24 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:49:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClientMaxBodySize.hpp"

ClientMaxBodySize::ClientMaxBodySize(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc(
            "ClientMaxBodySize", "http|server|location", context);
    value.push_back("1m");
    this->_type = "client_max_body_size";
    this->_is_context = false;
    this->_value_inline = value;
}

ClientMaxBodySize::ClientMaxBodySize(string raw_value, string context) {
    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc(
            "ClientMaxBodySize", "http|server|location", context);
    this->_type = "client_max_body_size";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

ClientMaxBodySize::~ClientMaxBodySize() {}
